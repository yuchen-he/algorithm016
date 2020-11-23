/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int counts[26] = {0};      //创建一个包含26的元素的数组 -> 模拟a-z
        for (int i=0; i<s.size(); i++) {
            counts[s[i] - 'a']++;          //关键代码：'z' - 'a' 将会返回字母表中的顺序差
            counts[t[i] - 'a']--;
        }

        for (int j=0; j<26; j++) {
            if (counts[j] != 0) return false;
        }
        return true;
    }
};
// @lc code=end

