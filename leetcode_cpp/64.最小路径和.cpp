/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // 解法一: dp自底向上 (时间O(m*n)，空间O(m*n))
        // 1. 最优子结构/子问题: 由于只能向右/下走，minPathSum(i,j) = min(minPathSum(i+1,j)，minPathSum(i,j+1))
        // 2. 储存中间状态: 用一个2维数组，并且自底向上储存状态
        // 3. dp方程: res[i][j] = (res[i+1][j], res[i][j+1])
        // vector<vector<int>> res = grid;
        // int row_num = grid.size();
        // int col_num = grid[0].size();

        // for (int i = row_num - 2; i >= 0; i--) {
        //     res[i][col_num - 1] += res[i+1][col_num - 1];
        // }
        // for (int j = col_num - 2; j >= 0; j--) {
        //     res[row_num - 1][j] += res[row_num - 1][j+1];
        // }

        // for (int i = row_num - 2; i >= 0; i--) {
        //     for (int j = col_num - 2; j >= 0; j--) {
        //         res[i][j] += min(res[i+1][j], res[i][j+1]);
        //     }
        // }
        // return res[0][0];

        // 解法二: 解法一空间优化 && 自顶向下写一遍 -> 空间O(n)
        // 思想: 上面2中，只需要保存下一行的值（因为求(i,j)时，只需要i+1或者j+1，而i+1是在i之前计算的）
        // 在自顶向下中，就是只需要保存上一行的值
        int row_num = grid.size();
        int col_num = grid[0].size();
        vector<int> dp(col_num, 0);
        dp[0] = grid[0][0];

        for (int i=1; i<col_num; i++) {
            dp[i] = grid[0][i] + dp[i-1];
        }

        for (int i = 1; i < row_num; i++) {
            dp[0] = dp[0] + grid[i][0];
            for (int j = 1; j < col_num; j++) {
                dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
            }
        }
        return dp[col_num-1];

        // 解法三: dp自顶向下，每次只保存上一行的值
    }
};
// @lc code=end