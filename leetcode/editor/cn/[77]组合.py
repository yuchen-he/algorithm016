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
        # 剪枝1: 每次select时，要比之前添加的数大，否则(1,3)和(3,1)会重复
        # 剪枝2: 如果n=6,k=4， 那么第一层肯定不能添加4及4以上的数(因为4,5,6不够凑齐k个数的组合了)
        #                    那么第二层肯定不能添加5及5以上的数（因为5,6凑不齐k-1个数的组合了）
        #       -> 因此，每次select的上界也有要求，不能超过n-k+len(track)+2
        res = []

        def dfs(track, start):
            # terminator
            if len(track) == k:
                res.append(track)
                return

                # process
            for i in range(start + 1, n - k + len(track) + 2):  # 剪枝
                dfs(track + [i], i)

        dfs([], 0)
        return res

        # 解法二：
        # 自己想出来的数学归纳法: 找n和n-1的结果的联系 -> self.combine(i - 1, k - 1)中的每个元素都加上现在的i
        # res = []
        # # terminator
        # if k == 0:
        #     return [[]]
        #
        # # process & drill down
        # for i in range(k, n+1):
        #     for elem in self.combine(i - 1, k - 1):
        #         res.append(elem + [i])          # 这里不能用elem.append（因为elem可能是空list）
        #
        # return res


# leetcode submit region end(Prohibit modification and deletion)

