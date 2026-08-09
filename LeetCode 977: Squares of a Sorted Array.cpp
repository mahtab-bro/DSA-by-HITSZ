The Question
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
-----------------------------------------------------------------------------------------
Your Simple Approach:
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];     // Square each element
        }
        sort(nums.begin(), nums.end());      // Sort the squares
        return nums;
    }
};
---------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();                          // n = 5 for our example
        
        // Result array to store sorted squares
        vector<int> result(n);
        
        // Two pointers: one at start, one at end
        int left = 0;                                 // Points to smallest (most negative)
        int right = n - 1;                            // Points to largest (most positive)
        
        // Fill result from END to START
        // Because largest squares come from the ends
        for (int i = n - 1; i >= 0; i--) {
            
            // Compare absolute values
            // The larger absolute value gives larger square
            if (abs(nums[left]) > abs(nums[right])) {
                // Left side has larger square
                result[i] = nums[left] * nums[left];  // Put square at position i
                left++;                               // Move left pointer right
            } else {
                // Right side has larger OR equal square
                result[i] = nums[right] * nums[right]; // Put square at position i
                right--;                              // Move right pointer left
            }
        }
        
        return result;
    }
};
