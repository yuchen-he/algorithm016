/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // https://leetcode-cn.com/problems/word-pattern/solution/cjian-ji-dai-ma-shuang-bai-7xing-by-orangeman/
        unordered_map<char, string> m1;
        unordered_map<string, char> m2; 
        stringstream ss(s);
        string word;
        
        for (char c: pattern) {
            // m1.count(c) > 0 && m1[c] != word: 防止pattern = "aa", str = "dog cat"返回true
            // m1.count(c) == 0 && m2.count(word) > 0: 防止pattern = "ab", str = "dog dog"返回true
            if (!(ss >> word) || 
                (m1.count(c) > 0 && m1[c] != word) || 
                (m1.count(c) == 0 && m2.count(word) > 0)) return false;
            m1[c] = word;
            m2[word] = c;
        }
        return (ss >> word) ? false : true;
    }
};
// @lc code=end

