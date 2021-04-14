# 存在一个 无向图 ，图中有 n 个节点。其中每个节点都有一个介于 0 到 n - 1 之间的唯一编号。给你一个二维数组 graph ，其中 graph[u]
#  是一个节点数组，由节点 u 的邻接节点组成。形式上，对于 graph[u] 中的每个 v ，都存在一条位于节点 u 和节点 v 之间的无向边。该无向图同时具有
# 以下属性：
#  
#  不存在自环（graph[u] 不包含 u）。 
#  不存在平行边（graph[u] 不包含重复值）。 
#  如果 v 在 graph[u] 内，那么 u 也应该在 graph[v] 内（该图是无向图） 
#  这个图可能不是连通图，也就是说两个节点 u 和 v 之间可能不存在一条连通彼此的路径。 
#  
# 
#  二分图 定义：如果能将一个图的节点集合分割成两个独立的子集 A 和 B ，并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合，就将这个图称
# 为 二分图 。 
# 
#  如果图是二分图，返回 true ；否则，返回 false 。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
# 输出：false
# 解释：不能将节点分割成两个独立的子集，以使每条边都连通一个子集中的一个节点与另一个子集中的一个节点。 
# 
#  示例 2： 
# 
#  
# 输入：graph = [[1,3],[0,2],[1,3],[0,2]]
# 输出：true
# 解释：可以将节点分成两组: {0, 2} 和 {1, 3} 。 
# 
#  
# 
#  提示： 
# 
#  
#  graph.length == n 
#  1 <= n <= 100 
#  0 <= graph[u].length < n 
#  0 <= graph[u][i] <= n - 1 
#  graph[u] 不会包含 u 
#  graph[u] 的所有值 互不相同 
#  如果 graph[u] 包含 v，那么 graph[v] 也会包含 u 
#  
#  Related Topics 深度优先搜索 广度优先搜索 图 
#  👍 232 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        """
        解法一: BFS
        * 从一个节点出发，给它分组，然后开始BFS，每层的节点放入跟上一层不同的组里面。
        * 易错点: 从一个点开始BFS，能遍历完所有的点吗？如果所有点是连通的，那就能，但题目说该图可能不是连通图。
        *       所以，要遍历每个顶点，再遍历当前顶点的所有相邻顶点，才能保证不漏点。
        * visited: 既保存节点是否已经被访问，还保存被分到的组（-1和1表示）
        """
        length = len(graph)
        if length <= 1: return True
        visited = [0] * length

        import collections
        q = collections.deque()
        for i in range(length):
            if visited[i] != 0: continue                       # 如果已经被分组，就跳过

            # 如果是连通图，一直可以把开头弄成1。如果不是，那一定是False，弄成1之后错了返回False就行
            visited[i] = 1                                     # 关键点: 将当前节点cur分到1组（不是在while循环里，说明while中pop出来的都是已经分好组的节点）
            q.append(i)
            while q:                                           # 从节点i开始，进行BFS
                cur = q.popleft()
                for neighbor in graph[cur]:                    # 访问所有邻接节点
                    if visited[neighbor] == visited[cur]:  # 如果邻接节点已经被分组，而且跟当前节点不一样，则返回false
                        return False
                    if visited[neighbor] == 0:
                        visited[neighbor] = -visited[cur]      # 因为pop出来的cur是已经分组的，所以只需要把neighbor分到另一组
                        q.append(neighbor)                     # 给neighbor分组后，再放入q中，以便BFS下去（之前已经分好组的neighbor不能加入q中）

        return True
# leetcode submit region end(Prohibit modification and deletion)
