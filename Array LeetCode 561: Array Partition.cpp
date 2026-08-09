The Question
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized.

Return the maximized sum.
Sort the array and take elements at even positions (0, 2, 4, ...).
----------------------------------------------------------------------------------------------------------
class Solution {                                                             // LeetCode requires Solution class
public:                                                                      // Make function accessible

    int arrayPairSum(vector<int>& nums) {                                  // Returns int, takes vector by ref
        sort(nums.begin(), nums.end());                                     // Sort array ascending

        int sum = 0;                                                        // Store sum of minimums

        for (int i = 0; i < nums.size(); i = i + 2) {                       // Step by 2 (take every 2nd element)
            sum = sum + nums[i];                                            // Add first element of each pair
        }

        return sum;                                                         // Return maximized sum
    }
};
