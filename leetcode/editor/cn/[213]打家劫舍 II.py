# 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的
# 房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。 
# 
#  给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：nums = [2,3,2]
# 输出：3
# 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
#  
# 
#  示例 2： 
# 
#  
# 输入：nums = [1,2,3,1]
# 输出：4
# 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
#      偷窃到的最高金额 = 1 + 3 = 4 。 
# 
#  示例 3： 
# 
#  
# 输入：nums = [0]
# 输出：0
#  
# 
#  
# 
#  提示： 
# 
#  
#  1 <= nums.length <= 100 
#  0 <= nums[i] <= 1000 
#  
#  Related Topics 动态规划 
#  👍 473 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def rob(self, nums: List[int]) -> int:
        """
        解法一: 拆分成两个问题
        因为题意可知第一个和最后一个房间最多只能偷其中一个。
        那么可以拆分成nums[1:]和nums[:-1]两个数组，分别求可偷到的最大金额(198题打家劫舍1)，然后取更大的那个

        198题解法: dp[i] = max(dp[i-1], dp[i-2] + nums[i])
                              1. i不偷  2. i偷（则i-1肯定不偷）
        """
        def helper(num):
            pre, cur = 0, 0        # pre表示i-2，cur表示i-1
            # 第一间到倒数第二间可偷到的最大值
            for i in range(len(num)):
                pre, cur = cur, max(cur, pre + num[i])
            return cur

        return max(helper(nums[1:]), helper(nums[:-1])) if len(nums) != 1 else nums[0]
# leetcode submit region end(Prohibit modification and deletion)
