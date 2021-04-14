# 假设按照升序排序的数组在预先未知的某个点上进行了旋转。 
# 
#  ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。 
# 
#  搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。 
# 
#  你可以假设数组中不存在重复的元素。 
# 
#  你的算法时间复杂度必须是 O(log n) 级别。 
# 
#  示例 1: 
# 
#  输入: nums = [4,5,6,7,0,1,2], target = 0
# 输出: 4
#  
# 
#  示例 2: 
# 
#  输入: nums = [4,5,6,7,0,1,2], target = 3
# 输出: -1 
#  Related Topics 数组 二分查找 
#  👍 989 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/ji-bai-liao-9983de-javayong-hu-by-reedfan/
        if len(nums) == 0: return -1
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target: return mid
            # nums[0] < nums[mid]: 说明左半边是有序的，右半边是有旋转的
            if nums[0] <= nums[mid]:                                   # 这里的<=是为了应对只剩两个数时，mid和0重复的情况
                if target >= nums[0] and target < nums[mid]:           # 这里的>=与上面的<=呼应。也可以上一行用<，这一行用>加<=
                    right = mid - 1
                else:
                    left = mid + 1
            # nums[0] > nums[mid]: 说明右半边是有序的，左半边是有旋转的
            else:
                if target > nums[mid] and target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1

        return -1
# leetcode submit region end(Prohibit modification and deletion)
