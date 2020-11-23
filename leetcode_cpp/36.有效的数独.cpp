/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // vector<vector<bool>> row(9, vector<bool>(9,0));
        // vector<vector<bool>> col(9, vector<bool>(9,0));
        // vector<vector<bool>> grid(9, vector<bool>(9,0));
        int row[9][9] = {0};
        int col[9][9] = {0};
        int grid[9][9] = {0};

        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] != '.') {
                    int idx = board[i][j] - '0';
                    // 如果出现过，则返回false
                    if (row[i][idx-1] || col[idx-1][j] || grid[(i/3)*3+j/3][idx-1]) {
                        return false;
                    }
                    // 如果没出现过，则将row, col, grid的该位置都变true
                    else {
                        row[i][idx-1] = true;
                        col[idx-1][j] = true;
                        grid[(i/3)*3+j/3][idx-1] = true;
                    }
                }
            }
        }

        return true;
    }
};
// @lc code=end

