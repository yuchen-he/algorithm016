# 给你一个字符串 s，找到 s 中最长的回文子串。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：s = "babad"
# 输出："bab"
# 解释："aba" 同样是符合题意的答案。
#  
# 
#  示例 2： 
# 
#  
# 输入：s = "cbbd"
# 输出："bb"
#  
# 
#  示例 3： 
# 
#  
# 输入：s = "a"
# 输出："a"
#  
# 
#  示例 4： 
# 
#  
# 输入：s = "ac"
# 输出："a"
#  
# 
#  
# 
#  提示： 
# 
#  
#  1 <= s.length <= 1000 
#  s 仅由数字和英文字母（大写和/或小写）组成 
#  
#  Related Topics 字符串 动态规划 
#  👍 3212 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def longestPalindrome(self, s: str) -> str:
        """
        解法一: dp
       （参考:评论里的代码 https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/）
        主要思想: 当一个字符串的首尾字符相等时，如果去除首尾字符之后的字符串仍时回文子串的话，说明这个字符串时回文子串
                 -> 这就是状态转移的考虑
        二维填表，只需要填对角线的上半部分（因为只需要考虑i<j的这一段字符串）
        当s[i] == s[j]时：
          1. 如果j - i < 3: 说明i-j这个字符串长度不大于3，那么i和j之间最多只有一个字符，从而可以判断这个字符串一定回文
          2. 如果j + i >= 3: 需要状态转移方程，去看从i+1 ~ j-1的字符串是否是回文子串
                             -> dp[i][j] = dp[i+1][j-1]
                             -> 关键点: 遍历填表时要先填满1列（因为用到了[i+1][j-1]）
        """
        length = len(s)
        if length < 2:
            return s

        dp = [[True] * length for _ in range(length)]
        maxlen = 1     # 记录最大回文子串长度
        start = 0      # 记录最大回文子串长度对应的起始位置

        # 只遍历对角线上半部分，并且优先遍历列
        for j in range(1, length):
            for i in range(0, j):
                if s[i] != s[j]:
                    dp[i][j] = False
                else:
                    if j - i < 3:
                        dp[i][j] = True
                    else:
                        dp[i][j] = dp[i+1][j-1]

                # 只要dp[i][j] == true 成立，表示s[i...j]是是回文串，从而更新maxlen和start
                if dp[i][j] and (j - i + 1 > maxlen):
                    maxlen = j - i + 1
                    start = i

        return s[start: start + maxlen]
# leetcode submit region end(Prohibit modification and deletion)
