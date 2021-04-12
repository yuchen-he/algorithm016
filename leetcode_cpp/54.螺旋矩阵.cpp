/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<int>& res, int startRow, int endRow, int startCol, int endCol) {
        // terminator
        if (startRow > endRow || startCol > endCol) {
            return;
        }
        else if (startRow >= endRow) {
            for (int j = startCol; j <= endCol; j++)
                res.push_back(matrix[startRow][j]); // 行
            return;
        }
        else if (startCol >= endCol) {
            for (int i = startRow + 1; i <= endRow; i++)
                res.push_back(matrix[i][endCol]);   // 列
            return;
        }
        else {
            // 分治
            for (int j = startCol; j <= endCol; j++)
                res.push_back(matrix[startRow][j]); // 上行
            for (int i = startRow + 1; i <= endRow; i++)
                res.push_back(matrix[i][endCol]); // 右列
            for (int j = endCol - 1; j >= startCol; j--)
                res.push_back(matrix[endRow][j]); // 下行
            for (int i = endRow - 1; i > startRow; i--)
                res.push_back(matrix[i][startCol]); // 左行

            // drill down
            dfs(matrix, res, startRow + 1, endRow - 1, startCol + 1, endCol - 1);
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        dfs(matrix, res, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
        return res;
    }
};
// @lc code=end

