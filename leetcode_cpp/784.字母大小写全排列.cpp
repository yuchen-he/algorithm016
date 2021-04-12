/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    void dfs(string S, vector<string>& res, string track, int level) {
        // 终止条件
        if (level == S.size()) {
            res.push_back(track);
            return;
        }

        // select and drill down
        if (S[level] >= 'a' && S[level] <= 'z')
        {
            track += toupper(S[level]);
            dfs(S, res, track, level + 1);
            // reverse
            track.pop_back();
        }
        else if (S[level] >= 'A' && S[level] <= 'Z')
        {
            track += tolower(S[level]);
            dfs(S, res, track, level + 1);
            // reverse
            track.pop_back();
        }
        dfs(S, res, track + S[level], level + 1);
    }

    vector<string> letterCasePermutation(string S) {
        /**
         * 解法一: dfs
         * 从第一个字符开始，遇到字母则分别用“大写”和“小写”drill down下去
         * 终止条件: level == len(S)，把字符串push到res里
        */
        vector<string> res;
        string track;
        dfs(S, res, track, 0);
        return res;
    }
};
// @lc code=end

