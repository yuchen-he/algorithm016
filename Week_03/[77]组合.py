# 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。 
# 
#  示例: 
# 
#  输入: n = 4, k = 2
# 输出:
# [
#   [2,4],
#   [3,4],
#   [2,3],
#   [1,2],
#   [1,3],
#   [1,4],
# ] 
#  Related Topics 回溯算法 
#  👍 405 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        # 自己想出来的解法: 找这一步与之前的联系，就是self.combine(i - 1, k - 1)中的每个元素都加上现在的i
        res = []
        # terminator
        if k == 0:
            return [[]]

        # process & drill down
        for i in range(k, n+1):
            for elem in self.combine(i - 1, k - 1):
                res.append(elem + [i])          # 这里不能用elem.append（因为elem可能是空list）

        return res


# leetcode submit region end(Prohibit modification and deletion)

