/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    void _generate(int max, string s, int l, int r) {
        // 复杂度: O(2^n)
        // terminator:
        // if (r > l || l > max) return;
        if (l == max && r == max) {
            res.push_back(s);
            return;
        }

        // process:
        // string s1 = s + '(';
        // string s2 = s + ')';

        // drill down:
        if (l < max) _generate(max, s + '(', l+1, r);
        if (r < l) _generate(max, s + ')', l, r+1);
    }

    vector<string> generateParenthesis(int n) {
        string s;
        _generate(n, s, 0, 0);
        return res;
    }
};
// @lc code=end

