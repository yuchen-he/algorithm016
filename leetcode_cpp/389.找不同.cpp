/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        // https://leetcode.com/problems/find-the-difference/discuss/861876/C%2B%2B-3-Approaches-or-Xor-operation-or-Hashmap-approach-or-sorting-approach
        /**
         * 解法二: 异或(^)
         * 1. 任一字符与0异或，结果为本身
         * 2. 任一字符与自己异或，结果为0
         * 3. 异或满足交换/结合律
        */
        int res = 0;
        for (char c: s) res ^= c;
        // res = s[0] ^ s[1] ^ ... ^ s[n]
        for (char c: t) res ^= c;
        // res = (s[0] ^ s[1] ^ ... ^ s[n]) ^ (t[0] ^ t[1] ^ ... ^ t[n+1])
        // 由于s和t中只有一个字符不同，其他都相同。
        // 由于交换/结合律，res中相同字符的两两异或变0，0和0异或也是0，最后res = 0 ^ t[n+1] (多出来的那个字符)
        return res;

        /**
         * 解法一: 哈希表/数组[26] (统计字母个数)
        */
        // unordered_map<char, int> m;
        // for (char c: s) m[c]++;
        // for (char c: t) {
        //     // t中第一次出现c，s中没有c -> 即map中不存在这个key
        //     if (!m.count(c)) return c;
        //     // t中第二次出现c，但s中只有一个c -> 即map中存在这个key，但value为0
        //     if (m.count(c) && m[c] == 0) return c;
        //     m[c]--;
        // }
        // // 以防函数出错（无返回值）
        // return ' ';
    }
};
// @lc code=end

