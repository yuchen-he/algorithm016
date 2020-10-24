/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
public:
    void helper(vector<vector<char>>& board, int h, int v) {
        // 不加这一句的话，某个位置被改为数字之后，又被后面递归过来的改成'B'，如此反复造成死递归
        if (board[h][v] != 'E' || board[h][v] == 'B') return;
        // 统计四周的雷
        int cnt = 0;
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i == 0 && j == 0) continue;
                // 判断越界
                if (h+i < 0 || h+i >= board.size() || v+j < 0 || v+j >= board[0].size()) continue;
                if (board[h+i][v+j] == 'M') cnt++;
            }
        }

        // 判断是否进行递归
        if (cnt > 0) {
            board[h][v] = char(cnt) + '0';
            return;
        }
        board[h][v] = 'B';
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i == 0 && j == 0) continue;
                // 判断越界
                if (h+i < 0 || h+i >= board.size() || v+j < 0 || v+j >= board[0].size()) continue;
                helper(board, h+i, v+j);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int h = click[0];
        int v = click[1];
        if (board[h][v] == 'M') board[h][v] = 'X';
        else if (board[h][v] == 'E') helper(board, h, v);
        return board;
    }
};
// @lc code=end

