// Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
// Each element in the array represents your maximum jump length at that position.
//
// Your goal is to reach the last index in the minimum number of jumps.
//
// Example:
//
//
// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
//     Jump 1 step from index 0 to 1, then 3 steps to the last index.
//
// Note:
//
// You can assume that you can always reach the last index.
//


class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt(0), maxlen(0), pre(0);
        if(nums.size() <= 1) return 0;
        for(int i = 0; i < nums.size(); ) {
            pre = maxlen;
            for(; i <= pre; ++i) {
                if(nums[i] + i > maxlen)
                    maxlen = nums[i] + i;
            }
            if(maxlen >= nums.size() - 1) {
                return cnt + 1;
            }
            cnt++;
        }
        return cnt;
    }
};
