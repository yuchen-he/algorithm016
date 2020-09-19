# 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。 
# 
#  你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。 
# 
#  
# 
#  示例: 
# 
#  给定 nums = [2, 7, 11, 15], target = 9
# 
# 因为 nums[0] + nums[1] = 2 + 7 = 9
# 所以返回 [0, 1]
#  
#  Related Topics 数组 哈希表 
#  👍 9059 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # 一遍hash
        hash_map = {}
        for i in range(len(nums)):
            if (target - nums[i]) in hash_map.keys():
                return [hash_map[target - nums[i]], i]
            else:
                hash_map[nums[i]] = i

        # 两边hash
        # ref = {}
        # for idx, elem in enumerate(nums):
        #     # ref[idx] = elem     # 字典不能通过值来找键(因为值会重复)，在下面无法查找
        #     ref[elem] = idx       # 所以这里把nums里面的值作为键
        #
        # for i, elem in enumerate(nums):
        #     j = ref.get(target - elem)        # get()通过键找值
        #     if j and i != j:      # 注意i有可能=j，这在题意里不允许
        #         return [i, j]

# leetcode submit region end(Prohibit modification and deletion)
