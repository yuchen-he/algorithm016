# 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复
# 的三元组。 
# 
#  注意：答案中不可以包含重复的三元组。 
# 
#  
# 
#  示例： 
# 
#  给定数组 nums = [-1, 0, 1, 2, -1, -4]，
# 
# 满足要求的三元组集合为：
# [
#   [-1, 0, 1],
#   [-1, -1, 2]
# ]
#  
#  Related Topics 数组 双指针 
#  👍 2559 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# 不重复是指数字不重复（不仅仅是index不重复），所以这里去重很重要
# 1. 暴力解法：3层循环挨个搜索，最后去重
# 2. a + b = -c，-c作为target（只是这个target不是固定的），for(target in nums), 从剩下的元素里面找两数之和=-target
#    2.1. hash表求两数之和 -> 总复杂度O(n^2) 比较慢
#    2.2. 给nums先排序，然后夹逼 -> 总复杂度O(n^2)
# https://leetcode-cn.com/problems/3sum/solution/3sumpai-xu-shuang-zhi-zhen-yi-dong-by-jyd/

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ret = []
        # head, tail = 0, len(nums) - 1     # 不需要对每个target都从头尾开始找，每次从i+1开始找能包含所有case

        # for i, target in enumerate(set(nums)):    # 用range可以直接得到index和nums[index],并且可以不遍历最后两个元素
        for i in range(len(nums)-2):
            if nums[i] > 0: break            # 因为hear和tail都比i大，所以不可能三个正数之和为0了
            if i > 0 and nums[i] == nums[i-1]: continue     # 去重：重复的target不用重复算
            head = i + 1
            tail = len(nums) - 1
            while head < tail:
                if nums[head] + nums[tail] == -nums[i]:
                    ret.append([nums[i], nums[head], nums[tail]])
                    head += 1              #碰到正解之后同时缩小左右两边范围
                    tail -= 1
                    while (head < tail and nums[head] == nums[head-1]): head += 1    # 去重：不取相等的元素
                    while (head < tail and nums[tail] == nums[tail+1]): tail -= 1
                elif nums[head] + nums[tail] > -nums[i]:
                    tail -= 1
                    # while (head < tail and nums[tail] == nums[tail+1]): tail -= 1    # sum!=0的情况不用去重
                elif nums[head] + nums[tail] < -nums[i]:
                    head += 1
                    # while (head < tail and nums[head] == nums[head - 1]): head += 1
        return ret
# leetcode submit region end(Prohibit modification and deletion)
