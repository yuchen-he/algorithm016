# 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c +
#  d 的值与 target 相等？找出所有满足条件且不重复的四元组。 
# 
#  注意： 
# 
#  答案中不可以包含重复的四元组。 
# 
#  示例： 
# 
#  给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
# 
# 满足要求的四元组集合为：
# [
#   [-1,  0, 0, 1],
#   [-2, -1, 1, 2],
#   [-2,  0, 0, 2]
# ]
#  
#  Related Topics 数组 哈希表 双指针 
#  👍 702 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        length = len(nums)
        if length < 4: return []

        nums.sort()
        res = []
        for i in range(length - 3):
            if i > 0 and nums[i] == nums[i - 1]: continue
            """下面两行剪枝能加速。注意一个break一个continue"""
            if nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] - target > 0:
                break
            if nums[i] + nums[length - 1] + nums[length - 2] + nums[length - 3] - target < 0:
                continue

            for j in range(i + 1, length - 2):
                """j > i + 1要加上，否则两连续数被丢掉了"""
                if j > i + 1 and nums[j] == nums[j - 1]: continue
                """下面两行剪枝能加速。注意一个break一个continue"""
                if nums[i] + nums[j] + nums[j + 1] + nums[j + 2] - target > 0:
                    break
                if nums[i] + nums[j] + nums[length - 1] + nums[length - 2] - target < 0:
                    continue
                left = j + 1
                right = length - 1

                while left < right:
                    sum = nums[i] + nums[j] + nums[left] + nums[right] - target
                    if sum == 0:
                        res.append([nums[i], nums[j], nums[left], nums[right]])
                        left += 1
                        right -= 1
                        while left < right and nums[left] == nums[left - 1]: left += 1
                        while left < right and nums[right] == nums[right + 1]: right -= 1
                    elif sum < 0:
                        left += 1
                    else:
                        right -= 1
        return res
# leetcode submit region end(Prohibit modification and deletion)
