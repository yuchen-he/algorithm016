# 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。 
# 
#  说明：解集不能包含重复的子集。 
# 
#  示例: 
# 
#  输入: [1,2,2]
# 输出:
# [
#   [2],
#   [1],
#   [1,2,2],
#   [2,2],
#   [1,2],
#   []
# ] 
#  Related Topics 数组 回溯算法 
#  👍 322 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def helper(track, start_id):
            res.append(track)
            for i in range(start_id, n):
                # 关键点：i > start_id （与全排列2不一样）
                # 因为在下一层添加相同元素是可以的，比如nums[3]=nums[4]时，在同一个track中需要逐个添加他们
                # 但是在同一层中不可以"选择"相同元素，因为同一层中都是添加元素到track的同一个位置 -> 所以用i>start_id来表示是在同一层
                if i > start_id and nums[i] == nums[i - 1]: continue
                helper(track + [nums[i]], i + 1)

        res = []
        n = len(nums)
        nums.sort()
        helper([], 0)
        return res
# leetcode submit region end(Prohibit modification and deletion)
