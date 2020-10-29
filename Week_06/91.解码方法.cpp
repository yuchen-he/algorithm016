/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        // 解法二: 优化空间复杂度到O(1)。
        //        因为只需要dp[i-1]和dp[i-2]，所以用pre和cur来代替
        //        中途用一个tmp来保存cur，方便一次循环结束后更新pre
        // 解法一: dp(类似于爬楼梯问题，但是这次要去除corner case)
        // dp方程: dp[i] = dp[i-1] + dp[i-2] （但是dp[i-1]和dp[i-2]有各自的需避开case）
        int num = s.size();
        if (num == 0 || s[0] == '0') return 0;
        vector<int> dp(num+1, 0);           // 关键: 省得需要在这里判断s[1]的值来决定dp[1]（否则dp方程用不了）
        dp[0] = 1;
        dp[1] = 1;

        for (int i=1; i<num; i++) {
            // s[i]对应dp[i+1]
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') { 
                    // s[i]不能单独被解码(那样整串字符无法全部被解码)，只能和s[i-1]一起被解码，并且s[i-1]只能为‘1’或‘2’
                    // 所以此时可以解码的数量就等于dp[i-1]（只能从s[i-2]跳过来）
                    dp[i+1] = dp[i-1];
                }
                else {
                    // s[i-1] >= '3’: 30/40/50...这些无法被解码，从而说明该字符串无解
                    // s[i-1] == '0': 两个连续的0无解
                    return 0;
                }
            }
            else {
                if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                    // 同上，只有s[i-1]能和s[i]组合在一起被解码时，dp方程才能用
                    // 否则，只能从s[i-1]跳过来（else中的情况）
                    dp[i+1] = dp[i] + dp[i-1];
                }
                else {
                    // s[i-1] == '0' 或者 s[i-1] >= '27'
                    dp[i+1] = dp[i];
                }
            }
        }
        return dp[num];
    }
};
// @lc code=end

