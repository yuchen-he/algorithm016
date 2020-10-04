/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.size() == 0 || g.size() == 0) return 0;
        int sum = 0;
        int j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for (int i=0; i<s.size(); i++) {
            if (j >= g.size()) return sum;
            if (s[i] >= g[j]) {
                sum += 1;
                j++;
            }
        }

        return sum;
    }
};
// @lc code=end

