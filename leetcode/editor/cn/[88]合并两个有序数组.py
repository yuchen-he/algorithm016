# 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。 
# 
#  
# 
#  说明: 
# 
#  
#  初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。 
#  你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。 
#  
# 
#  
# 
#  示例: 
# 
#  输入:
# nums1 = [1,2,3,0,0,0], m = 3
# nums2 = [2,5,6],       n = 3
# 
# 输出: [1,2,2,3,5,6] 
#  Related Topics 数组 双指针 
#  👍 628 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i = m - 1
        j = n - 1
        k = len(nums1) - 1
        while (j >= 0):
            if (i < 0):
                nums1[:k+1] = nums2[:j+1]
                break

            if (nums1[i] >= nums2[j]):
                nums1[k] = nums1[i]
                i -= 1
                k -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
                k -= 1

        # 另一种写法，更简洁漂亮
        # while m > 0 and n > 0:
        #     if nums1[m - 1] >= nums2[n - 1]:
        #         nums1[m + n - 1] = nums1[m - 1]
        #         m -= 1
        #     else:
        #         nums1[m + n - 1] = nums2[n - 1]
        #         n -= 1
        # if n > 0:
        #     nums1[:n] = nums2[:n]
# leetcode submit region end(Prohibit modification and deletion)
