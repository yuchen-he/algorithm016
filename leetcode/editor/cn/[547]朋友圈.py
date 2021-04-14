# 班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 
# 的朋友。所谓的朋友圈，是指所有朋友的集合。 
# 
#  给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你
# 必须输出所有学生中的已知的朋友圈总数。 
# 
#  
# 
#  示例 1： 
# 
#  输入：
# [[1,1,0],
#  [1,1,0],
#  [0,0,1]]
# 输出：2 
# 解释：已知学生 0 和学生 1 互为朋友，他们在一个朋友圈。
# 第2个学生自己在一个朋友圈。所以返回 2 。
#  
# 
#  示例 2： 
# 
#  输入：
# [[1,1,0],
#  [1,1,1],
#  [0,1,1]]
# 输出：1
# 解释：已知学生 0 和学生 1 互为朋友，学生 1 和学生 2 互为朋友，所以学生 0 和学生 2 也是朋友，所以他们三个在一个朋友圈，返回 1 。
#  
# 
#  
# 
#  提示： 
# 
#  
#  1 <= N <= 200 
#  M[i][i] == 1 
#  M[i][j] == M[j][i] 
#  
#  Related Topics 深度优先搜索 并查集 
#  👍 371 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        # 解法二: DFS(与图有关)
        # 解法一: 并查集
        class UnionFind:
            def __init__(self, n):
                self.count = n
                self.parent = [i for i in range(n)]

            def find(self, i):
                root = i
                while self.parent[root] != root:
                    root = self.parent[root]
                while self.parent[i] != i:
                    tmp = self.parent[i]
                    self.parent[i] = root
                    i = tmp
                return root

            def union(self, i, j):
                p1 = self.find(i)
                p2 = self.find(j)
                if p1 == p2:
                    return
                else:
                    self.parent[p1] = p2
                    self.count -= 1

        length = len(M)
        uf = UnionFind(length)

        for i in range(length):
            for j in range(i+1, length):             # 因为是对称矩阵，所以只需要遍历半边
                if M[i][j] == 1:
                    uf.union(i, j)

        return uf.count
# leetcode submit region end(Prohibit modification and deletion)
