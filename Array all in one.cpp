#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// ============================================================================
// PROBLEM 1: LeetCode 1732 - Find the Highest Altitude
// ============================================================================
class Solution1732 {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;              // Current altitude, starts at 0
        int maxAltitude = 0;           // Track highest altitude reached
        
        for (int g : gain) {           // Loop through each gain
            altitude = altitude + g;   // Add gain to get new altitude
            maxAltitude = max(maxAltitude, altitude); // Update max if higher
        }
        return maxAltitude;            // Return highest altitude
    }
};

// ============================================================================
// PROBLEM 2: LeetCode 3248 - Snake in Matrix
// ============================================================================
class Solution3248 {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int pos = 0;                   // Snake starts at cell 0
        
        for (string cmd : commands) {  // Loop through each command
            if (cmd == "RIGHT") pos = pos + 1;      // Right = +1
            else if (cmd == "LEFT") pos = pos - 1;  // Left = -1
            else if (cmd == "DOWN") pos = pos + n;  // Down = +n (next row)
            else if (cmd == "UP") pos = pos - n;    // Up = -n (previous row)
        }
        return pos;                    // Return final position
    }
};

// ============================================================================
// PROBLEM 3: LeetCode 3132 - Check if Grid Satisfies Conditions
// ============================================================================
class Solution3132 {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size();           // m = number of rows
        int n = grid[0].size();        // n = number of columns
        
        for (int i = 0; i < m; i++) {          // Loop each row
            for (int j = 0; j < n; j++) {      // Loop each column
                // Rule 1: Cell must EQUAL cell below (if exists)
                if (i + 1 < m && grid[i][j] != grid[i+1][j]) return false;
                // Rule 2: Cell must DIFFER from cell to right (if exists)
                if (j + 1 < n && grid[i][j] == grid[i][j+1]) return false;
            }
        }
        return true;                   // All conditions satisfied
    }
};

// ============================================================================
// PROBLEM 4: LeetCode 3033 - Modify the Matrix
// ============================================================================
class Solution3033 {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();         // m = number of rows
        int n = matrix[0].size();      // n = number of columns
        
        vector<int> colMax(n, -1);     // Store max per column, init to -1
        
        // FIRST PASS: Find max in each column
        for (int j = 0; j < n; j++) {          // Loop each column
            for (int i = 0; i < m; i++) {      // Loop each row in column
                colMax[j] = max(colMax[j], matrix[i][j]); // Update max
            }
        }
        
        // SECOND PASS: Replace -1s with column max
        for (int i = 0; i < m; i++) {          // Loop each row
            for (int j = 0; j < n; j++) {      // Loop each column
                if (matrix[i][j] == -1) {      // If cell is -1
                    matrix[i][j] = colMax[j];  // Replace with column's max
                }
            }
        }
        return matrix;                 // Return modified matrix
    }
};

// ============================================================================
// PROBLEM 5: LeetCode 3028 - Ant on the Boundary
// ============================================================================
class Solution3028 {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int position = 0;              // Ant starts at boundary (0)
        int count = 0;                 // Count returns to boundary
        
        for (int num : nums) {         // Loop each movement
            position = position + num; // Move right (+num) or left (-num)
            if (position == 0) count++; // If on boundary, increment count
        }
        return count;                  // Return total returns
    }
};

// ============================================================================
// PROBLEM 6: LeetCode 1652 - Defuse the Bomb
// ============================================================================
class Solution1652 {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();           // n = array length
        vector<int> result(n, 0);      // Initialize result with zeros
        
        if (k == 0) return result;     // If k=0, all values are 0
        
        for (int i = 0; i < n; i++) {          // Loop each position
            int sum = 0;                       // Sum of k numbers
            
            if (k > 0) {                       // If k positive, sum NEXT k
                for (int j = 1; j <= k; j++) {
                    sum += code[(i + j) % n];  // Circular indexing (wrap)
                }
            } else {                           // If k negative, sum PREVIOUS k
                for (int j = 1; j <= -k; j++) {
                    sum += code[(i - j + n) % n]; // +n to avoid negative indices
                }
            }
            result[i] = sum;                   // Store sum at position i
        }
        return result;                 // Return decrypted array
    }
};

// ============================================================================
// PROBLEM 7: LeetCode 2951 - Find the Peaks
// ============================================================================
class Solution2951 {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        int n = mountain.size();       // n = array length
        vector<int> result;            // Store peak indices
        
        for (int i = 1; i < n - 1; i++) {          // Skip first and last
            if (mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1]) {
                result.push_back(i);               // Add peak index
            }
        }
        return result;                 // Return all peak indices
    }
};

// ============================================================================
// PROBLEM 8: LeetCode 561 - Array Partition
// ============================================================================
class Solution561 {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort ascending
        
        int sum = 0;                   // Store sum of minimums
        for (int i = 0; i < nums.size(); i = i + 2) {
            sum = sum + nums[i];       // Take every 2nd element (even indices)
        }
        return sum;                    // Return maximized sum
    }
};

// ============================================================================
// PROBLEM 9: LeetCode 977 - Squares of a Sorted Array
// ============================================================================
class Solution977 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();           // n = array length
        vector<int> result(n);         // Result array
        int left = 0;                  // Pointer at start
        int right = n - 1;             // Pointer at end
        
        for (int i = n - 1; i >= 0; i--) {       // Fill from largest to smallest
            if (abs(nums[left]) > abs(nums[right])) {
                result[i] = nums[left] * nums[left]; // Square of left is larger
                left++;                            // Move left pointer right
            } else {
                result[i] = nums[right] * nums[right]; // Square of right is larger
                right--;                           // Move right pointer left
            }
        }
        return result;                 // Return sorted squares
    }
};
