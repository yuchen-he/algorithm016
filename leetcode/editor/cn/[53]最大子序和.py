# 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
# 输出：6
# 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
#  
# 
#  示例 2： 
# 
#  
# 输入：nums = [1]
# 输出：1
#  
# 
#  示例 3： 
# 
#  
# 输入：nums = [0]
# 输出：0
#  
# 
#  示例 4： 
# 
#  
# 输入：nums = [-1]
# 输出：-1
#  
# 
#  示例 5： 
# 
#  
# 输入：nums = [-100000]
# 输出：-100000
#  
# 
#  
# 
#  提示： 
# 
#  
#  1 <= nums.length <= 3 * 104 
#  -105 <= nums[i] <= 105 
#  
# 
#  
# 
#  进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。 
#  Related Topics 数组 分治算法 动态规划 
#  👍 2868 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        """
        解法一: dp
        用1维数组保存中间状态，记录截止到某位置（并且使用该位置）时能达到的最大和
        Option 1: 与i-1之前的位置连接起来
        Option 2: 从i位置开始重新来（这种情况一般时因为dp[i-1] < 0）
        注意点: 最终返回的不是dp[-1]，而是max(dp[:])
        """
        # length = len(nums)
        # if length == 0: return 0
        #
        # dp = nums
        # for i in range(1, length):
        #     dp[i] = max(dp[i - 1] + nums[i], nums[i])
        #
        # return max(dp[:])

        """
        解法一: dp，空间优化
        由于只需要用到dp[i-1]，因此只需要一个变量preSum保存中间状态即可。
        注意点: 因为最终要返回的是max(dp[:])，所以每次要更新maxSum
        """
        length = len(nums)
        if length == 0: return 0

        maxSum, preSum = nums[0], nums[0]
        for i in range(1, length):
            preSum = max(preSum + nums[i], nums[i])
            maxSum = max(preSum, maxSum)

        return maxSum
# leetcode submit region end(Prohibit modification and deletion)
