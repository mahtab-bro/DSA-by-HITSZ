 The Question
Given a 0-indexed m x n integer matrix, create a new 0-indexed matrix called answer. Make answer equal to matrix, then replace each element with the value -1 with the maximum element in its respective column.

Return the matrix answer.
----------------------------------------------------------------------------------------------------------
  class Solution {                                                      // LeetCode requires Solution class
public:                                                               // Make function accessible

    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) { // Returns 2D vector, takes matrix by ref
        int m = matrix.size();                                        // m = number of rows
        int n = matrix[0].size();                                     // n = number of columns

        vector<int> colMax(n, -1);                                    // Store max per column, init to -1

        for (int j = 0; j < n; j++) {                                 // Loop each column
            for (int i = 0; i < m; i++) {                             // Loop each row in this column
                colMax[j] = max(colMax[j], matrix[i][j]);             // Update max if current cell larger
            }
        }

        for (int i = 0; i < m; i++) {                                 // Loop each row
            for (int j = 0; j < n; j++) {                             // Loop each column in this row
                if (matrix[i][j] == -1) {                             // Check if current cell is -1
                    matrix[i][j] = colMax[j];                         // Replace -1 with column's maximum
                }
            }
        }

        return matrix;                                                // Return modified matrix
    }
};
