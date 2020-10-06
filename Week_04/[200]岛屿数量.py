# 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
# 
#  岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。 
# 
#  此外，你可以假设该网格的四条边均被水包围。 
# 
#  
# 
#  示例 1: 
# 
#  输入:
# [
# ['1','1','1','1','0'],
# ['1','1','0','1','0'],
# ['1','1','0','0','0'],
# ['0','0','0','0','0']
# ]
# 输出: 1
#  
# 
#  示例 2: 
# 
#  输入:
# [
# ['1','1','0','0','0'],
# ['1','1','0','0','0'],
# ['0','0','1','0','0'],
# ['0','0','0','1','1']
# ]
# 输出: 3
# 解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
#  
#  Related Topics 深度优先搜索 广度优先搜索 并查集 
#  👍 794 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # Stefan Pochman解法：老牛逼了
        # def numIslands(self, grid):
        #     def sink(i, j):
        #         if 0 <= i < len(grid) and 0 <= j < len(grid[i]) and grid[i][j] == '1':
        #             grid[i][j] = '0'
        #             map(sink, (i + 1, i - 1, i, i), (j, j, j + 1, j - 1))
        #             return 1
        #         return 0
        #
        #     return sum(sink(i, j) for i in range(len(grid)) for j in range(len(grid[i])))

        def helper(h, v, grid):
            if h >= len(grid) or v >= len(grid[0]) or h < 0 or v < 0: return 0
            if grid[h][v] == '1':
                grid[h][v] = '0'
                helper(h - 1, v, grid)
                helper(h + 1, v, grid)
                helper(h, v + 1, grid)
                helper(h, v - 1, grid)

        if len(grid) == 0: return 0
        h, v, sum = 0, 0, 0
        for h in range(len(grid)):
            for v in range(len(grid[0])):
                if grid[h][v] == '1':
                    sum += 1
                    helper(h, v, grid)
        return sum

# leetcode submit region end(Prohibit modification and deletion)
