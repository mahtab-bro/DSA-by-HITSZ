 The Question
An ant is on a boundary. It sometimes goes left and sometimes right.

You are given an array of non-zero integers nums. The ant starts reading nums from the first element to its end. At each step, it moves according to the value of the current element:

If nums[i] < 0, it moves left by -nums[i] units.

If nums[i] > 0, it moves right by nums[i] units.

Return the number of times the ant returns to the boundary.
--------------------------------------------------------------------------------------------------------

class Solution {                                                            // LeetCode requires Solution class
public:                                                                     // Make function accessible

    int returnToBoundaryCount(vector<int>& nums) {                          // Returns count, takes vector by ref
        int position = 0;                                                   // Ant starts at boundary (0)
        int count = 0;                                                      // Count how many times returns to 0

        for (int num : nums) {                                              // Loop through each movement
            position = position + num;                                      // Add num (right if positive, left if negative)

            if (position == 0) {                                            // Check if ant is exactly on boundary
                count++;                                                    // If yes, increment count
            }
        }

        return count;                                                       // Return total times on boundary
    }
};
