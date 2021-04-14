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
        # 解法二: 递归DFS简洁版本
        # def sink(i, j):
        #     if 0 <= i < len(grid) and 0 <= j < len(grid[i]) and grid[i][j] == '1':
        #         grid[i][j] = '0'
        #         list(map(sink, (i + 1, i - 1, i, i), (j, j, j + 1, j - 1)))
        #         # 如果不用list会导致计算错误，因为map函数返回的是一个map object，而不是一个list或者tuple
        #         # https://www.jianshu.com/p/9f260147a602
        #         # map(sink, (i + 1, i - 1, i, i), (j, j, j + 1, j - 1))
        #         return 1
        #     return 0
        # return sum(sink(i, j) for i in range(len(grid)) for j in range(len(grid[i])))

        # 解法一: 递归DFS
        # def helper(h, v, grid):
        #     if h >= len(grid) or v >= len(grid[0]) or h < 0 or v < 0: return 0
        #     if grid[h][v] == '1':
        #         grid[h][v] = '0'
        #         helper(h - 1, v, grid)
        #         helper(h + 1, v, grid)
        #         helper(h, v + 1, grid)
        #         helper(h, v - 1, grid)
        #
        # if len(grid) == 0: return 0
        # h, v, sum = 0, 0, 0
        # for h in range(len(grid)):
        #     for v in range(len(grid[0])):
        #         if grid[h][v] == '1':
        #             sum += 1
        #             helper(h, v, grid)
        # return sum

        # 解法三: 并查集(速度最快，因为只是O(m*n)，没有多余的递归操作)
        # 知识点: 在成员函数中可以创建一个类
        class UnionFind:
            def __init__(self, n):
                self.count = n
                self.parent = [i for i in range(n)]

            def find(self, i):
                root = i
                while self.parent[root] != root:
                    # 查找集合最顶端的节点
                    root = self.parent[root]
                while self.parent[i] != i:
                    # 路径压缩
                    x = i
                    i = self.parent[i]  # 把查看的节点往上移一位，成为待查看节点
                    self.parent[x] = root  # 把本次查看的节点的parent直接指向刚才已经找到的集合顶端节点root
                return root

            def union(self, i, j):
                root_i = self.find(i)
                root_j = self.find(j)
                if root_i == root_j:
                    return  # 是同一个节点的话，没必要合并，所以不进行任何操作
                self.parent[root_i] = root_j
                self.count -= 1

        row = len(grid)
        if row == 0: return 0
        col = len(grid[0])

        uf = UnionFind(row * col)
        water_count = 0

        def get_index(x, y):
            # 通过grid中的index来计算parent数组中对应的index
            return x * col + y

        for i in range(row):
            for j in range(col):
                if grid[i][j] == '1':
                    water_count += 1
                else:
                    if i + 1 < row and grid[i + 1][j] == '1':
                        uf.union(get_index(i, j), get_index(i + 1, j))
                    if j + 1 < col and grid[i][j + 1] == '1':
                        uf.union(get_index(i, j), get_index(i, j + 1))
                    # 只有当前格子为'1'的情况时，因为初始化uf时count已经把每个格子当成一个岛屿了，所以water_count不加，self.count不减就行

        return uf.count - water_count
# leetcode submit region end(Prohibit modification and deletion)
