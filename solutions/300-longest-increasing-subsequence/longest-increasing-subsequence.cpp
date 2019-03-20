// Given an unsorted array of integers, find the length of longest increasing subsequence.
//
// Example:
//
//
// Input: [10,9,2,5,3,7,101,18]
// Output: 4 
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
//
// Note: 
//
//
// 	There may be more than one LIS combination, it is only necessary for you to return the length.
// 	Your algorithm should run in O(n2) complexity.
//
//
// Follow up: Could you improve it to O(n log n) time complexity?
//


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> lis(1, nums[0]);
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > lis.back())
                lis.push_back(nums[i]);
            else {
                auto index = std::lower_bound(lis.begin(), lis.end(), nums[i]);
                *index = nums[i];
            }
        }
        return lis.size();
     }
};
