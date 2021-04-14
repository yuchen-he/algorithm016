/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
private:
    void unionFind(vector<int>& parent, int i, int j) {
        int p_i = find(parent, i);
        int p_j = find(parent, j);
        if (p_i != p_j) {
            parent[p_i] = p_j;
        }
    }

    int find(vector<int>& parent, int i) {
        int root = i;
        while (parent[root] != root) {
            root = parent[root];
        }

        while (parent[i] != i) {
            int tmp = parent[i];
            parent[i] = root;
            i = tmp;
        }
        return root;
    }

public:
    void solve(vector<vector<char>>& board) {
        /**
         * 解法一: dfs
         * 从边界的'O'开始dfs，然后把所有相连的'O'都置'1'
         * 把剩余的'O'都置为'X'，最后再把'1'改为'O'
        */
        /**
         * 解法二: 并查集
         * Trick: 增加一个dummy在并查集的末尾，遍历棋盘:
         *      1. 遇到边界的'O': 令其与dummy相连
         *      2. 遇到非边界'O': 令其与上下左右的'O'相连 (这样如果它与边界'O'是相连的话，就会最终与dummy拥有共同root)
         * 最终遍历棋盘，与dummy相连的'O'不变，其他的置'X'
        */

        // 初始化并查集
        int rows = board.size();
        int cols = board[0].size();
        vector<int> parent(rows * cols + 1, 0);
        for (int k = 0; k <= rows * cols; k++) {
            parent[k] = k;      // 增加的一个位置(idx = rows * cols)代表dummy
        }

        // 建立并查集的连接
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                        unionFind(parent, i * cols + j, rows * cols);      // 边界'O'与dummy相连
                    }
                    else {
                        if (board[i-1][j] == 'O') unionFind(parent, i * cols + j, (i - 1) * cols + j);
                        if (board[i+1][j] == 'O') unionFind(parent, i * cols + j, (i + 1) * cols + j);
                        if (board[i][j-1] == 'O') unionFind(parent, i * cols + j, i * cols + j - 1);
                        if (board[i][j+1] == 'O') unionFind(parent, i * cols + j, i * cols + j + 1);
                    }
                }
            }
        }

        // 把与dummy不相连的'O'置'X'
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                if (board[i][j] == 'O' && find(parent, i * cols + j) != find(parent, rows * cols)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// @lc code=end

