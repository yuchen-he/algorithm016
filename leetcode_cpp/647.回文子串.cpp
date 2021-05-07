/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        // 解法: dp。基本与第5题的解法一样，通过填二维表来解决
        int length = s.size();
        vector<vector<int>> dp(length, vector<int>(length, 0));
        int res = 0;

        for (int j = 0; j < length; j++) {
            for (int i = 0; i <= j; i++) {
                if (s[i] == s[j]) {
                    if (j - i < 3) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = dp[i+1][j-1];
                    }

                    if (dp[i][j] == 1) res++;
                }
            }
        }

        return res;
    }
};
// @lc code=end

