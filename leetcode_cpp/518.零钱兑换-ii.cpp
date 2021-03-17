/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /**
         * 解法一: dp
         * 注意点: 因为是组合问题，会有很多重复出现（例如[1,2,5]中凑3时，不是dp[3] = dp[2] + dp[1]，因为(1,2)和(2,1)会重复）
        */
        if (amount == 0) return 1;
        sort(coins.begin(), coins.end());

        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int k = 0; k < coins.size(); k++) {
            for (int i = 1; i < amount + 1; i++) {
                if (i < coins[k]) continue;
                dp[i] += dp[i - coins[k]];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

