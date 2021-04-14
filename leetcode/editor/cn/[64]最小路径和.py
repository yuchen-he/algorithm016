# 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。 
# 
#  说明：每次只能向下或者向右移动一步。 
# 
#  示例: 
# 
#  输入:
# [
#   [1,3,1],
#   [1,5,1],
#   [4,2,1]
# ]
# 输出: 7
# 解释: 因为路径 1→3→1→1→1 的总和最小。
#  
#  Related Topics 数组 动态规划 
#  👍 706 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        # 剪枝: dp不需要用m x n,可以只需要上一层
        dp = grid[0]
        for i in range(1, col):
            dp[i] += dp[i - 1]

        for i in range(1, row):
            dp[0] += grid[i][0]
            for j in range(1, col):
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j]

        return dp[col - 1]
# leetcode submit region end(Prohibit modification and deletion)
