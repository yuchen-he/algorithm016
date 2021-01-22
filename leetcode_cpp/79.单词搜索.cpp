/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty()) return false;
        row = board.size();
        col = board[0].size();

        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (backtrack(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }

private:
    int row;
    int col;

    bool backtrack(vector<vector<char>>& board, string& word, int k, int i, int j) {
        if (i < 0 || j < 0 || i >= row || j >= col) return false;
        if (board[i][j] != word[k]) return false;
        // terminator
        if (k == word.size() - 1) return true;

        char tmp = board[i][j];
        board[i][j] = '#';
        if (backtrack(board, word, k+1, i-1, j) 
            || backtrack(board, word, k+1, i+1, j)
            || backtrack(board, word, k+1, i, j-1) 
            || backtrack(board, word, k+1, i, j+1)) {
                return true;
        }
        board[i][j] = tmp;
        return false;
    }
};
// @lc code=end

