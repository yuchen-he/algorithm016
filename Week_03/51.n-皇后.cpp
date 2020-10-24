/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<string> make_puzzle(vector<int> track) {
        // make a real puzzle from a track
        int len = track.size();
        vector<string> puzzle;
        for (int i = 0; i < len; i++) {
            string row = string(len, '.');
            row[track[i]] = 'Q';
            puzzle.push_back(row);
        }
        return puzzle;

    }
    void backtrack(vector<vector<string>>& res, vector<int>& track, int level, int max_num, vector<bool> col, vector<bool> main, vector<bool> sub) {
        // terminator
        if (track.size() == max_num) {
            res.push_back(make_puzzle(track));
            return;
        }

        // drill down
        for (int i = 0; i < max_num; i++) {
            // 剪枝
            if (col[i] || main[level - i + max_num - 1] || sub[level + i]) continue;
            track.push_back(i);
            col[i] = true;
            main[level - i + max_num - 1] = true;      // 同一条主对角线的任一坐标点都会对应一个main中的同一个index(从0开始)
            sub[level + i] = true;                     // 同一条副对角线的任一坐标点都会对应一个sub中的同一个index(从0开始)
            backtrack(res, track, level + 1, max_num, col, main, sub);
            col[i] = false;
            main[level - i + max_num - 1] = false;
            sub[level + i] = false;
            track.pop_back();
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> track;
        // vector<vector<int>> used(n, vector<int>(n, 0));
        vector<bool> col(n, false);
        vector<bool> main(2*n-1, false);     // 一个棋盘上，主对角线总共有2n-1条，每一条的(横坐标-纵坐标)相等/固定
        vector<bool> sub(2*n-1, false);      // 一个棋盘上，副对角线总共有2n-1条，每一条的(横坐标+纵坐标)相等/固定
        backtrack(res, track, 0, n, col, main, sub);
        return res;
    }
};
// @lc code=end

