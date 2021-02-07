/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /**
         * 解法一: dp
         * dp[i] = nums[i] if dp[i] <= 0 
         * dp[i] = nums[i] + dp[i-1] if dp[i] > 0 
        */
        vector<int> dp(nums);
        int max_val = nums[0];

        for (int i=1; i<nums.size(); i++) {
            dp[i] = (dp[i-1] > 0) ? (dp[i] + dp[i-1]) : dp[i];
            if (dp[i] > max_val) {max_val = dp[i];}
        }
        return max_val;
    }
};
// @lc code=end

