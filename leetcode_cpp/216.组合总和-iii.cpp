/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    void backtrack(vector<vector<int>>& res, int k, int n, vector<int>& track, int curSum, int startNum) {
        // 终止条件
        if (track.size() == k) {
            if (curSum == n) {
                res.push_back(track);
            }
            return;
        }

        // 选择 & 回溯
        for (int i = startNum; i <= 9; i++) {
            // 剪枝: 如果总和超过n了，则没必要再进行下去了
            if (i + curSum > n) break;

            // 选择 & 撤销
            track.push_back(i);
            backtrack(res, k, n, track, curSum + i, i + 1);
            track.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> track;
        backtrack(res, k, n, track, 0, 1);
        return res;
    }
};
// @lc code=end

