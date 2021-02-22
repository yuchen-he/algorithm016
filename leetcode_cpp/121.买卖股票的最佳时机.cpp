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
         * 解法一: 暴力解法 O(N^2) 双指针遍历数组
         * 解法二: dp
         * 需要一个二组数组dp[i][j]来保存中间状态(即截止到当天的最大利润)。i表示某一天，j表示当天是否持股.
         * 1. j=0，即第i天不持股
         *    1.1. 截止到i-1天持股了，然后第i天卖掉（此时对应dp值是当天股价减dp[i-1][0]）
         *    1.2. 截止到i-1天不持股，第i天也不买入（此时维持dp[i-1][0]）
         * 2. j=1，即第i天持股
         *    2.1. 截止到i-1天持股了，第i天继续持有（此时维持dp[i-1][1]）
         *    2.2. 截止到i-1天不持股，第i天买入（此时对应dp值是负的当天股价）
         * 上述1.1和1.2，以及2.1和2.2中，选取最大值
        */
        // int length = prices.size();
        // vector<vector<int>> dp(length, vector<int>(2, 0));
        // dp[0][1] = -prices[0];

        // for (int i=1; i<length; i++) {
        //     dp[i][1] = max(-prices[i], dp[i-1][1]);
        //     dp[i][0] = max(dp[i-1][1] + prices[i], dp[i-1][0]);
        // }

        // return dp[length-1][0];

        /**
         * 解法三: dp，优化空间
         * 因为只用到了i-1天的状态，所以只需要用两个变量保存状态
        */
        int pre_no  = 0;
        int pre_yes = -prices[0];

        for (int i=1; i<prices.size(); i++) {
            pre_no = max(pre_yes + prices[i], pre_no);
            pre_yes = max(-prices[i], pre_yes);
        }

        return pre_no;
    }
};
// @lc code=end

