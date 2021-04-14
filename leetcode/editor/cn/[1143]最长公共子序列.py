# 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。 
# 
#  一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。 
# 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
#  
# 
#  若这两个字符串没有公共子序列，则返回 0。 
# 
#  
# 
#  示例 1: 
# 
#  输入：text1 = "abcde", text2 = "ace" 
# 输出：3  
# 解释：最长公共子序列是 "ace"，它的长度为 3。
#  
# 
#  示例 2: 
# 
#  输入：text1 = "abc", text2 = "abc"
# 输出：3
# 解释：最长公共子序列是 "abc"，它的长度为 3。
#  
# 
#  示例 3: 
# 
#  输入：text1 = "abc", text2 = "def"
# 输出：0
# 解释：两个字符串没有公共子序列，返回 0。
#  
# 
#  
# 
#  提示: 
# 
#  
#  1 <= text1.length <= 1000 
#  1 <= text2.length <= 1000 
#  输入的字符串只含有小写英文字符。 
#  
#  Related Topics 动态规划 
#  👍 366 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # if test1[i] == test2[j]: dp[i][j] = dp[i-1][j-1] + 1
        # if test1[i] != test2[j]: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        # 改进: 只需要1维数组保存一行，再加上upper_left的值
        len1 = len(text1)
        len2 = len(text2)
        dp = [0] * (len1 + 1)    # 关键点: 增加一列0，以便max(dp[i-1][j], dp[i][j-1])时"j-1"不会越界

        for i in range(len2):
            upper_left = 0  # 关键点: 每次发生换行时，upper_left又变成0（因为增加了一列全是0的）
            for j in range(len1):
                tmp = dp[j+1]
                if text1[j] == text2[i]:
                    dp[j+1] = 1 + upper_left
                else:
                    dp[j+1] = max(dp[j+1], dp[j])
                upper_left = tmp
        return dp[len1]
# leetcode submit region end(Prohibit modification and deletion)
