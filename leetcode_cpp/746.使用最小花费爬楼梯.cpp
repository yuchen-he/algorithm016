/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        /**
         * 解法一: dp
         * dp方程: dp[i] = cost[i] + min(dp[i-2], dp[i-1])
         * 关键点: 最后是要到达len(cost)处，而非len(cost)-1。所以最后return时返回 min(dp[-1], dp[-2])
        */
        vector<int> dp = cost;
        int length = cost.size();
        for (int i=2; i<length; i++) {
            dp[i] += min(dp[i-2], dp[i-1]);
        }
        return min(dp[length-1], dp[length-2]);
    }
};
// @lc code=end

