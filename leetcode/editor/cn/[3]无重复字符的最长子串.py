# 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。 
# 
#  
# 
#  示例 1: 
# 
#  
# 输入: s = "abcabcbb"
# 输出: 3 
# 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
#  
# 
#  示例 2: 
# 
#  
# 输入: s = "bbbbb"
# 输出: 1
# 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
#  
# 
#  示例 3: 
# 
#  
# 输入: s = "pwwkew"
# 输出: 3
# 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
#      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
#  
# 
#  示例 4: 
# 
#  
# 输入: s = ""
# 输出: 0
#  
# 
#  
# 
#  提示： 
# 
#  
#  0 <= s.length <= 5 * 104 
#  s 由英文字母、数字、符号和空格组成 
#  
#  Related Topics 哈希表 双指针 字符串 Sliding Window 
#  👍 4761 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        """解法一: 暴力法, O(N^3?)
        每遍历1个字符时，建立一个set保存已用字符，从当前字符往后找一直到无重复字符出现，如果大于maxlen则赋值给它
        """
        # cur = 0
        # maxlen = 0
        #
        # while cur < len(s):
        #     next = cur + 1
        #     used = set(s[cur])
        #     curlen = 1
        #
        #     while next < len(s):
        #         if s[next] not in used:
        #             used.add(s[next])
        #             curlen += 1
        #             next += 1
        #         else:
        #             break
        #     if curlen > maxlen:
        #         maxlen = curlen
        #     cur += 1
        # return maxlen

        """解法二: 滑动窗口（双指针实现）
        看goodnote笔记"""
        if not s: return 0
        start = end = 0
        m = collections.defaultdict()
        maxlen = 0

        while end < len(s):
            if s[end] in m.keys() and m[s[end]] >= start:   # 关键点：m[s[end]] >= start
                maxlen = max(maxlen, end - start)
                start = m[s[end]] + 1

            m[s[end]] = end
            end += 1
        return max(maxlen, end - start)
# leetcode submit region end(Prohibit modification and deletion)
