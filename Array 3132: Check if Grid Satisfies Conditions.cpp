LeetCode 3132: Check if Grid Satisfies Conditions
📖 The Question (As stated on LeetCode)
You are given a 2D matrix grid of size m x n. You need to check if each cell grid[i][j] is:

Equal to the cell below it → grid[i][j] == grid[i+1][j] (if it exists)

Different from the cell to its right → grid[i][j] != grid[i][j+1] (if it exists)

Return true if all the cells satisfy these conditions, otherwise return false.

-----------------------------------------------------------------------------------------------
class Solution {                                                    // LeetCode requires Solution class
public:                                                             // Make function accessible outside class

    bool satisfiesConditions(vector<vector<int>>& grid) {           // Returns true/false, takes 2D grid
        int m = grid.size();                                        // m = number of rows
        int n = grid[0].size();                                     // n = number of columns

        for (int i = 0; i < m; i++) {                               // Loop through each row
            for (int j = 0; j < n; j++) {                           // Loop through each column

                // Check Rule 1: Cell must EQUAL cell below it
                if (i + 1 < m && grid[i][j] != grid[i+1][j]) {     // If row below exists AND values differ
                    return false;                                   // Rule 1 failed → grid invalid
                }

                // Check Rule 2: Cell must DIFFER from cell to its right
                if (j + 1 < n && grid[i][j] == grid[i][j+1]) {     // If column right exists AND values equal
                    return false;                                   // Rule 2 failed → grid invalid
                }
            }
        }

        return true;                                                // All cells passed both checks ✅
    }
};
