/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /**
         * 解法一: 整体二分法 -> O(m*n)
         * 解法二: 先二分确定行，再二分确定列 -> O(log(m)*log(n))
        */
        int rows = matrix.size(), cols = matrix[0].size();

        int row_begin = 0, row_end = rows - 1;
        while (row_begin < row_end) {
            int row_mid = (row_begin + row_end + 1) >> 1;      // 需要向上取整，理由在下面
            if (matrix[row_mid][0] == target) return true;
            else if (matrix[row_mid][0] > target) {
                row_end = row_mid - 1;
            }
            else {
                row_begin = row_mid;     // 因为target可能在row_mid这一行 -> 但这样的话需要向上取整找row_mid，否则会陷入死循环
            }
        }

        // 此时row_begin == row_end，并且target在他们所在的行
        int col_begin = 0, col_end = cols - 1;
        while (col_begin < col_end) {
            int col_mid = (col_begin + col_end + 1) >> 1;       // 这里也向上取整，以防要找的数比第一列更小时，导致最终col_end变成-1了
            if (matrix[row_end][col_mid] == target) return true;
            else if (matrix[row_end][col_mid] > target) {
                col_end = col_mid - 1;
            }
            else {
                col_begin = col_mid;           // 向上取整了之后这里就不用col_mid+1了，以防要找的数比最后一列更大时，导致最终col_end越界了
            }
        }

        // return false;        // 错误。[[1,3]]中target为3的话，col_mid到不了3的位置
        // 此时col_begin == col_end
        return (matrix[row_end][col_end] == target);
    }
};
// @lc code=end

