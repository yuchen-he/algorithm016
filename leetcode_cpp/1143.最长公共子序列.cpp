/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 解法二: 优化空间，利用一个upper_left来保存左上角的dp值，并且每次更新它
        int col = text1.size();
        int row = text2.size();
        int upper_left = 0;

        // 优化点: 相当于分别在text1和text2之前加一个空字符，以便循环时不需要单独判断第一行和第一列
        vector<int> dp(row+1, 0);
        for (int i=1; i<row+1; i++) {
            for (int j=1; j<col+1; j++) {
                // TODO
            }
        }
        return dp[col];

        // 解法一: dp，建立text1为横轴，text2为纵轴的2维dp表
        // 1. [i][j]字符相同时，dp[i][j] = dp[i-1][j-1] + 1  <-  注意，不是max(dp[i-1][j], dp[i][j-1]) + 1
        // 2. [i][j]字符不同时，dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        // int col = text1.size();
        // int row = text2.size();

        // // 优化点: 相当于分别在text1和text2之前加一个空字符，以便循环时不需要单独判断第一行和第一列
        // vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        // for (int i=1; i<row+1; i++) {
        //     for (int j=1; j<col+1; j++) {
        //         if (text2[i-1] == text1[j-1]) {
        //             dp[i][j] = dp[i-1][j-1] + 1;
        //         }
        //         else {
        //             dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[row][col];
    }
};
// @lc code=end

