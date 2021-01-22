/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        /**
         * 解法一: 暴力法。两层循环，内层循环中没找到同样的字符即返回，O(N^2)
         * 解法二: 遍历两边+哈希表。第一遍记录元素出现次数，第二遍找到第一个次数为1的，O(N)
         * 解法三: 一次遍历+前后分别find，O(N^2)?
         * （为什么这个方法反而快？因为s特别长的话解法二永远要花2N，而解法三可能很快找到第一个不重复的）
         * 解法四: 哈希表中放pair同时保存出现次数和idx。unordered_map<char, pair<int, int>> m;
        */
        // 解法二
        // map<char, int> m;
        // for (auto c: s) {
        //     m[c]++;
        // }
        // for (int i=0; i<s.size(); i++) {
        //     if (m[s[i]] == 1) return i;
        // }
        // return -1;

        // 解法三
        for (int i=0; i<s.size(); i++) {
            if (s.find(s[i]) == s.rfind(s[i])) return i;
        }
        return -1;
    }
};
// @lc code=end

