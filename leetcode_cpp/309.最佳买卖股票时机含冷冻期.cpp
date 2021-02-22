/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /**
         * 解法一: 利用通解
         * 关键点1: 交易次数k无限大，即dp[i][k-1][0/1] = dp[i][k][0/1]
         * 关键点2: 如果在第i天可以买入，则说明i-1天必须啥也没干（即保持了dp[i-2][k]的[0]和[1]）
         *         => 因此dp[i][k][1]只需要从dp[i-2][k][0]来算即可(就能保证有一天冷冻期)
         *         1. 如果i-1天卖出了，则第i天为冷冻期
         *         2. 如果i-1天买入了，则第i天不能重复买入
         * 状态转移方程: 其中的k可以删掉，因为没有其他k-1等状态
         *         T[i][k][0] = max(T[i - 1][k][0], T[i - 1][k][1] + prices[i])
         *         T[i][k][1] = max(T[i - 1][k][1], T[i - 2][k][0] - prices[i])
         *         => 因为状态只与i-1和i-2相关，因此只需要用变量来保存
        */
        if (prices.size() == 0) return 0;
        int profit0 = 0, profit1 = -prices[0], prevProfit0 = 0;
        for (int i=1; i<prices.size(); i++) {
            int nextProfit0 = max(profit0, profit1 + prices[i]);
            int nextProfit1 = max(profit1, prevProfit0 - prices[i]);
            prevProfit0 = profit0;
            profit0 = nextProfit0;
            profit1 = nextProfit1;
        }
        return profit0;
    }
};
// @lc code=end

