# 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。 
# 
#  有效字符串需满足： 
# 
#  
#  左括号必须用相同类型的右括号闭合。 
#  左括号必须以正确的顺序闭合。 
#  
# 
#  注意空字符串可被认为是有效字符串。 
# 
#  示例 1: 
# 
#  输入: "()"
# 输出: true
#  
# 
#  示例 2: 
# 
#  输入: "()[]{}"
# 输出: true
#  
# 
#  示例 3: 
# 
#  输入: "(]"
# 输出: false
#  
# 
#  示例 4: 
# 
#  输入: "([)]"
# 输出: false
#  
# 
#  示例 5: 
# 
#  输入: "{[]}"
# 输出: true 
#  Related Topics 栈 字符串 
#  👍 1857 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def isValid(self, s: str) -> bool:
        # 可以先判断是否为奇数长度，是则没必要进行下去了
        if len(s) % 2 == 1:
            return False

        stack = ["?"]
        relat = {')': '(', ']': '[', '}': '{'}
        for elem in s:
            if elem in relat.keys():
                if stack.pop() != relat[elem]: return False
            else: stack.append(elem)

        return len(stack) == 1

        # 自己写的第一遍代码，太长了！！！
        # ret = True         # 不需要ret，直接返回true/false就行了
        # if not s:
        #     return ret
        #
        # relat = {')': '(', ']': '[', '}': '{'}
        # stack = []
        # for elem in s:
        #     if elem in relat.keys():
        #         if len(stack) == 0:     # 有个trick，先给stack一个元素，就不用担心stack为空时判断右括号了
        #             ret = False
        #             return ret
        #         elif stack[-1] != relat[elem]:    # 因为提前给了stack一个元素，所以这里可以判断和pop同时进行
        #             ret = False         # 这两行太啰嗦，直接返回False就行了
        #             return ret
        #         else:
        #             stack.pop()
        #     else:
        #         stack.append(elem)
        #
        # if len(stack) == 0:       # 这几行可以简化为return len(stack) == 1，就是bool返回了
        #     return ret
        # else:
        #     ret = False
        #     return ret

# leetcode submit region end(Prohibit modification and deletion)
