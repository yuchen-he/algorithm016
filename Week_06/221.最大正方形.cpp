/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dp法，递推计算以当前点为正方形右下角时的最大边长
        // 状态转移方程： dp(i,j)=min(dp(i−1,j),dp(i−1,j−1),dp(i,j−1))+1
        // 优化方案：因为每次只需要与上/左/左上比较，并且左肯定在当前点之前计算的，所以只需一个数组+变量(up_left)来保存状态
        if (matrix.empty()) return 0;
        int row_num = matrix.size();
        int col_num = matrix[0].size();

        vector<int> pre_row(col_num, 0);
        int upper_left = 0;                  // 保存左上角
        int max_length = 0;

        for (int i=0; i<row_num; i++) {
            for (int j=0; j<col_num; j++) {
                int pre_up = pre_row[j];
                if (!i || !j || matrix[i][j] == '0') {
                    pre_row[j] = matrix[i][j] - '0';        // '1' - '0' = 1 (int)
                }
                else {
                    // matrix[i][j] == '1' && i != 0 && j != 0时
                    pre_row[j] = min(pre_row[j], min(pre_row[j-1], upper_left)) + 1;
                }
                max_length = max(max_length, pre_row[j]);   // 现在的pre_row[j]是已经更新过的当前位置
                upper_left = pre_up;         // 关键点: 在同一行中循环时，当前的pre_up就是下一次循环时的upper_left
                // 当下一次循环为下一行时，不会触发使用upper_left的情况，因为会进入!j的条件中
            }
        }
        return max_length * max_length;
    }
};
// @lc code=end

