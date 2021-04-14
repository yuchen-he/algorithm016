# 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。 
# 
#  最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。 
# 
#  你可以假设除了整数 0 之外，这个整数不会以零开头。 
# 
#  示例 1: 
# 
#  输入: [1,2,3]
# 输出: [1,2,4]
# 解释: 输入数组表示数字 123。
#  
# 
#  示例 2: 
# 
#  输入: [4,3,2,1]
# 输出: [4,3,2,2]
# 解释: 输入数组表示数字 4321。
#  
#  Related Topics 数组 
#  👍 545 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        # 把数组元素连接成str，再转为int，然后直接加1，然后再转回为数组：速度跟正常解法差不多
        result = []
        str_digits = ''.join(str(i) for i in digits)
        int_digits = int(str_digits) + 1
        str_digits = str(int_digits)
        for i in str_digits:
            result.append(int(i))
        return result

        # 正常解法
        # i = len(digits) - 1
        # while (i >= 0):
        #     if digits[i] != 9:
        #         digits[i] += 1
        #         return digits
        #     else:
        #         digits[i] = 0
        #         i -= 1
        #
        # digits.append(0)
        # digits[0] = 1
        # return digits
# leetcode submit region end(Prohibit modification and deletion)
