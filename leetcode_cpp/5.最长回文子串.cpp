/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        if (length == 1) return s;

        vector<vector<bool>> dp(length, vector<bool>(length, true));
        int maxlen = 1;
        int start = 0;
        for (int j = 1; j < length ; j++) {
            for (int i = 0; i < j; i++) {
                // 只有i和j位置的字符相同，才有可能是回文子串
                if (s[i] == s[j]) {
                    // 如果j-i<=2，那么说明i和j位置之间最多只有一个字符，则i～j的字符串肯定回文(就不需要操作了，因为初始化就是true)
                    if (j - i > 2) {
                        // 如果j-i>2，那么要看去掉i和j位置的子串是否是回文子串
                        dp[i][j] = dp[i+1][j-1];
                    }
                    // 如果i~j为回文子串，就是判断是否这个子串是最长的（确定长度和子串起始位置即可）
                    if (dp[i][j] == true and j - i + 1 > maxlen) {
                        maxlen = j - i + 1;
                        start = i;
                    }
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        
        // string res;
        // for (int i = start; i < start + maxlen; i++) {
        //     res += s[i];
        // }
        // return res;

        // 获取string的子串
        return s.substr(start, maxlen);
    }
};
// @lc code=end

