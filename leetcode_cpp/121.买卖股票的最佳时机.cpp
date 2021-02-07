/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /**
         * 解法一: 暴力解法 O(N^2)
         * 双指针遍历数组
        */
        /**
         * 解法二: dp
         * 需要一个二组数组dp[i][j]来保存中间状态。i表示利润，j表示当天是否持股.
         * 1. j=0，即第i天不持股
         *    1.1. 截止到i-1天持股了，然后第i天卖掉（此时对应dp值是当天股价减dp[i-1][0]）
         *    1.2. 截止到i-1天不持股，第i天也不买入（此时维持dp[i-1][0]）
         * 2. j=1，即第i天持股
         *    2.1. 截止到i-1天持股了，第i天继续持有（此时维持dp[i-1][1]）
         *    2.2. 截止到i-1天不持股，第i天买入（此时对应dp值是负的当天股价）
         * 上述1.1和1.2，以及2.1和2.2中，选取最大值
        */
        int length = prices.size();
        vector<vector<int>> dp = {2, vector<int>(length, 0)};

        for (int i=0; i<length; i++) {
            //
        }
    }
};
// @lc code=end

