/*
 * LEETCODE 1732 - Find the Highest Altitude
 * 
 * Problem: A biker goes on a road trip with n + 1 points at different altitudes. 
 * The biker starts at point 0 with altitude 0. You are given an array gain of 
 * length n where gain[i] is the net gain in altitude between point i and point i + 1.
 * Return the highest altitude reached.
 * 
 * Example 1: gain = [-5,1,5,0,-7] → Output: 1 (altitudes: [0,-5,-4,1,1,-6])
 * Example 2: gain = [-4,-3,-2,-1,4,3,2] → Output: 0 (altitudes: [0,-4,-7,-9,-10,-6,-3,-1])
 */

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;        // Current altitude, starts at 0
        int maxAltitude = 0;     // Highest altitude seen so far, starts at 0
        
        for (int g : gain) {     // Loop through each gain value
            altitude += g;       // Add gain to get new altitude
            maxAltitude = max(maxAltitude, altitude); // Update max if higher
        }
        
        return maxAltitude;      // Return the highest altitude reached
    }
};

/*
 * LEETCODE 3248 - Snake in Matrix
 * 
 * Problem: There is a snake in an n x n matrix grid. Each cell is identified by 
 * grid[i][j] = (i * n) + j. The snake starts at cell 0 and follows commands.
 * Commands: "UP", "RIGHT", "DOWN", "LEFT". Return the final cell position.
 * 
 * Example 1: n=2, commands=["RIGHT","DOWN"] → Output: 3
 * Example 2: n=3, commands=["DOWN","RIGHT","UP"] → Output: 1
 */

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int pos = 0;                         // Snake starts at cell 0
        
        for (string cmd : commands) {        // Loop through each command
            if (cmd == "RIGHT") pos += 1;    // Right = +1 in row-major order
            else if (cmd == "LEFT") pos -= 1; // Left = -1 in row-major order
            else if (cmd == "DOWN") pos += n; // Down = +n (next row, same column)
            else if (cmd == "UP") pos -= n;   // Up = -n (previous row, same column)
        }
        
        return pos;                          // Return final position
    }
};

/*
 * LEETCODE 3132 - Check if Grid Satisfies Conditions
 * 
 * Problem: Given a 2D matrix grid of size m x n. Check if each cell is:
 * 1. Equal to the cell below it: grid[i][j] == grid[i+1][j] (if exists)
 * 2. Different from the cell to its right: grid[i][j] != grid[i][j+1] (if exists)
 * Return true if all conditions satisfied, false otherwise.
 * 
 * Example 1: grid=[[1,0,2],[1,0,2]] → Output: true
 * Example 2: grid=[[1,0,2],[1,0,3]] → Output: false
 */

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size();                 // m = number of rows
        int n = grid[0].size();              // n = number of columns
        
        for (int i = 0; i < m; i++) {        // Loop through each row
            for (int j = 0; j < n; j++) {    // Loop through each column
                // Rule 1: Cell must EQUAL cell below it
                if (i + 1 < m && grid[i][j] != grid[i+1][j]) return false;
                // Rule 2: Cell must DIFFER from cell to its right
                if (j + 1 < n && grid[i][j] == grid[i][j+1]) return false;
            }
        }
        return true;                         // All checks passed
    }
};

/*
 * LEETCODE 3033 - Modify the Matrix
 * 
 * Problem: Given an m x n integer matrix, create a new matrix answer equal to matrix,
 * then replace each -1 with the maximum element in its respective column.
 * Return the modified matrix.
 * 
 * Example 1: matrix=[[1,2,-1],[4,-1,6],[7,8,9]] → Output: [[1,2,9],[4,8,6],[7,8,9]]
 * Example 2: matrix=[[-1,-1,-1],[-1,-1,-1]] → Output: [[-1,-1,-1],[-1,-1,-1]]
 */

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();               // m = number of rows
        int n = matrix[0].size();            // n = number of columns
        
        vector<int> colMax(n, -1);           // Store max per column, init to -1
        
        // FIRST PASS: Find maximum in each column
        for (int j = 0; j < n; j++) {        // Loop through each column
            for (int i = 0; i < m; i++) {    // Loop through each row in this column
                colMax[j] = max(colMax[j], matrix[i][j]); // Update max if larger
            }
        }
        
        // SECOND PASS: Replace -1s with column maximums
        for (int i = 0; i < m; i++) {        // Loop through each row
            for (int j = 0; j < n; j++) {    // Loop through each column
                if (matrix[i][j] == -1) {    // Check if cell is -1
                    matrix[i][j] = colMax[j]; // Replace with column's max
                }
            }
        }
        
        return matrix;                       // Return modified matrix
    }
};

/*
 * LEETCODE 3028 - Ant on the Boundary
 * 
 * Problem: An ant is on a boundary. It moves left if nums[i] < 0 and right if nums[i] > 0.
 * Return the number of times the ant returns to the boundary (position 0).
 * Note: Only counts if ant lands exactly on 0 after a move, not if it crosses over.
 * 
 * Example 1: nums=[2,3,-5] → Output: 1 (2→5→0, returns once)
 * Example 2: nums=[3,2,-3,-4] → Output: 0 (never returns to 0)
 */

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int position = 0;                    // Ant starts at boundary (0)
        int count = 0;                       // Count how many times returns to 0
        
        for (int num : nums) {               // Loop through each movement
            position += num;                 // Add num (right if positive, left if negative)
            if (position == 0) count++;      // If exactly on boundary, increment count
        }
        
        return count;                        // Return total times on boundary
    }
};

/*
 * LEETCODE 1652 - Defuse the Bomb
 * 
 * Problem: Given a circular array code of length n and a key k:
 * - If k > 0: Replace ith number with sum of next k numbers
 * - If k < 0: Replace ith number with sum of previous k numbers
 * - If k == 0: Replace ith number with 0
 * Return the decrypted code.
 * 
 * Example 1: code=[5,7,1,4], k=3 → Output: [12,10,16,13]
 * Example 2: code=[1,2,3,4], k=0 → Output: [0,0,0,0]
 * Example 3: code=[2,4,9,3], k=-2 → Output: [12,5,6,13]
 */

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();                 // n = length of circular array
        vector<int> result(n, 0);            // Initialize result with zeros
        
        if (k == 0) return result;           // If k=0, all values become 0
        
        for (int i = 0; i < n; i++) {        // Loop through each position
            int sum = 0;                     // Sum of k numbers for current position
            
            if (k > 0) {                     // Sum NEXT k numbers (to the right)
                for (int j = 1; j <= k; j++) {
                    sum += code[(i + j) % n]; // Circular index using modulo
                }
            } else {                         // Sum PREVIOUS k numbers (to the left)
                for (int j = 1; j <= -k; j++) { // -k converts negative to positive
                    sum += code[(i - j + n) % n]; // +n handles negative indices
                }
            }
            
            result[i] = sum;                 // Store sum for current position
        }
        
        return result;                       // Return decrypted array
    }
};

/*
 * LEETCODE 2951 - Find the Peaks
 * 
 * Problem: Given a 0-indexed array mountain. Find all peaks (element strictly greater
 * than both neighbors). First and last elements are not peaks. Return indices of peaks.
 * 
 * Example 1: mountain=[2,4,4] → Output: []
 * Example 2: mountain=[1,3,2,4,5,3,2] → Output: [1,3]
 * Example 3: mountain=[1,2,1,3,5,6,4] → Output: [1,2,5]
 */

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        int n = mountain.size();             // n = array length
        vector<int> result;                  // Store peak indices
        
        for (int i = 1; i < n - 1; i++) {    // Skip first and last (0 and n-1)
            if (mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1]) {
                result.push_back(i);         // Add index if greater than both neighbors
            }
        }
        
        return result;                       // Return all peak indices
    }
};

/*
 * LEETCODE 561 - Array Partition
 * 
 * Problem: Given an integer array nums of 2n integers, group into n pairs (a1,b1),...
 * such that sum of min(ai, bi) is maximized. Return the maximized sum.
 * 
 * Example 1: nums=[1,4,3,2] → Output: 4 (pair as (1,2),(3,4) → min=1+3=4)
 * Example 2: nums=[6,2,6,5,1,2] → Output: 9 (pair as (1,2),(2,5),(6,6) → min=1+2+6=9)
 */

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());      // Sort array in ascending order
        
        int sum = 0;                         // Store sum of minimums
        
        for (int i = 0; i < nums.size(); i += 2) { // Step by 2 (take every 2nd element)
            sum += nums[i];                  // Add first element of each pair (the smaller one)
        }
        
        return sum;                          // Return maximized sum
    }
};

/*
 * LEETCODE 977 - Squares of a Sorted Array
 * 
 * Problem: Given an integer array nums sorted in non-decreasing order, return an array
 * of the squares of each number sorted in non-decreasing order.
 * 
 * Example 1: nums=[-4,-1,0,3,10] → Output: [0,1,9,16,100]
 * Example 2: nums=[-7,-3,2,3,11] → Output: [4,9,9,49,121]
 * 
 * Note: Two-pointer approach for O(n) time. Square + sort also works in O(n log n).
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();                 // n = array length
        vector<int> result(n);               // Result array of same size
        int left = 0;                        // Pointer at start (most negative)
        int right = n - 1;                   // Pointer at end (most positive)
        
        for (int i = n - 1; i >= 0; i--) {   // Fill from largest to smallest
            if (abs(nums[left]) > abs(nums[right])) { // Larger absolute value → larger square
                result[i] = nums[left] * nums[left];  // Square of left is larger
                left++;                               // Move left pointer right
            } else {
                result[i] = nums[right] * nums[right]; // Square of right is larger/equal
                right--;                              // Move right pointer left
            }
        }
        
        return result;                       // Return sorted squares
    }
};
