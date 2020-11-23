/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 解法一: 回溯算法（跟括号生成一样，终止条件为到达[m][n]），时间复杂度O(?)
        // 解法二: 动态规划
        // 中间状态dp[i][j]: 第一行，第一列都为1
        // dp方程：dp[i][j] = dp[i-1][j] + dp[i][j-1] 
        // 优化方案：只保存上一行的结果（因为前一位的dp值已经更新了）
        if (m == 0 || n == 0) return 0;
        vector<int> dp(m, 1);
        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++) {
                dp[j] = dp[j-1] + dp[j];
            }
        }
        return dp[m-1];
    }
};
// @lc code=end

