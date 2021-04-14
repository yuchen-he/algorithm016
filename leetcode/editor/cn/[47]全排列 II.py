# 给定一个可包含重复数字的序列，返回所有不重复的全排列。 
# 
#  示例: 
# 
#  输入: [1,1,2]
# 输出:
# [
#   [1,1,2],
#   [1,2,1],
#   [2,1,1]
# ] 
#  Related Topics 回溯算法 
#  👍 492 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def helper(track):
            # terminator
            if len(track) == n:
                res.append(track.copy())
                return 0

            for i in range(0, n):
                if used[i] == 1: continue
                if i > 0 and nums[i] == nums[i - 1] and used[i - 1] == 0: continue

                used[i] = 1
                helper(track + [nums[i]])
                used[i] = 0

        res = []
        n = len(nums)
        used = [0 for _ in range(n)]
        helper([])
        return res
# leetcode submit region end(Prohibit modification and deletion)
