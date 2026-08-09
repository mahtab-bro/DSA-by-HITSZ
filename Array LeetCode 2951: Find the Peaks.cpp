The Question
You are given a 0-indexed array mountain. Your task is to find all the peaks in the mountain array.

Return an array that consists of indices of peaks in the given array in any order.

Notes:

A peak is defined as an element that is strictly greater than its neighboring elements.

The first and last elements of the array are not a peak.
--------------------------------------------------------------------------------------------------------
  class Solution {                                                             // LeetCode requires Solution class
public:                                                                      // Make function accessible

    vector<int> findPeaks(vector<int>& mountain) {                         // Returns vector of indices
        int n = mountain.size();                                            // n = array length
        vector<int> result;                                                 // Store peak indices

        for (int i = 1; i < n - 1; i++) {                                   // Skip first and last (0 and n-1)
            if (mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1]) { // Check if greater than both neighbors
                result.push_back(i);                                        // Add index to result
            }
        }

        return result;                                                      // Return all peak indices
    }
};
