# 树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。 
# 
#  给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），其中
#  edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。 
# 
#  可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度
# 树 。 
# 
#  请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。 
# 树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：n = 4, edges = [[1,0],[1,2],[1,3]]
# 输出：[1]
# 解释：如图所示，当根是标签为 1 的节点时，树的高度是 1 ，这是唯一的最小高度树。 
# 
#  示例 2： 
# 
#  
# 输入：n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
# 输出：[3,4]
#  
# 
#  示例 3： 
# 
#  
# 输入：n = 1, edges = []
# 输出：[0]
#  
# 
#  示例 4： 
# 
#  
# 输入：n = 2, edges = [[0,1]]
# 输出：[0,1]
#  
# 
#  
# 
#  
#  
# 
#  提示： 
# 
#  
#  1 <= n <= 2 * 104 
#  edges.length == n - 1 
#  0 <= ai, bi < n 
#  ai != bi 
#  所有 (ai, bi) 互不相同 
#  给定的输入 保证 是一棵树，并且 不会有重复的边 
#  
#  Related Topics 广度优先搜索 图 
#  👍 301 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        """
        解法二: BFS（类似拓扑排序，但是每次要删除的是所有入度为1的节点）
               解法一的问题：从根节点出发要循环遍历所有节点，并且计算每一个节点出发时的高度
        前提: 最后的根节点只可能为1个或者2个。(剩2个可以是因为: 这是无向图，这俩节点既然连接的话而且目前入度都，谁做root都成立)
            （https://blog.csdn.net/u012416259/article/details/98334588）
        方法: 从叶子节点出发，每次删除所有叶子节点（即入度为1，而非0，因为是无向图），直至只剩1或2个节点
        """
        if not edges: return [0]

        # 邻接表和入度表
        neighbors = [[] for _ in range(n)]
        inDegree = [0 for _ in range(n)]
        for i, j in edges:
            neighbors[i].append(j)
            neighbors[j].append(i)
            inDegree[i] += 1
            inDegree[j] += 1

        # 把入度为1的节点放入队列
        q = collections.deque()
        for idx in range(n):
            if inDegree[idx] == 1: q.append(idx)

        count = n
        size = len(q)
        while count > 2:   # 关键点: 最后的根节点只可能为1个或者2个
            # 一次性删去size个节点
            count -= size
            for _ in range(size):
                cur = q.popleft()

                # 入度减为0
                inDegree[cur] = 0

                # 更新cur的邻接节点的inDegree
                for neighbor in neighbors[cur]:
                    # 这个因为没有把之前删掉的节点从其他节点的neighbor中删除，所以要判断是否是已删除节点（即入度为0）
                    if inDegree[neighbor] != 0:
                        inDegree[neighbor] -= 1
                        if inDegree[neighbor] == 1:
                            q.append(neighbor)

            # 更新q的长度为了下次循环
            size = len(q)

        res = []
        while q:
            tmp = q.popleft()
            res.append(tmp)
        return res

        """
        解法一: BFS O(N*N？)  ->  超时
        循环从图中每一节点出发，计算出截止到最末尾的高度，如果<最小高度，则把root添加到res中
        """

        # # 返回值
        # res = []
        #
        # # 邻接表 (无向图，所以正反都要添加进来)
        # neighbors = [[] for _ in range(n)]
        # for i, j in edges:
        #     neighbors[i].append(j)
        #     neighbors[j].append(i)
        #
        # # 已访问（一定不能忘）
        # visited = [False for _ in range(n)]
        #
        # # 队列
        # q = collections.deque()
        #
        # # 最小高度
        # min_height = math.inf
        #
        # for i in range(n):
        #     q.append(i)
        #     cur_height = 0
        #     while q:
        #         # BFS
        #         size = len(q)
        #         for _ in range(size):
        #             pre = q.popleft()
        #             visited[pre] = True
        #             for j in neighbors[pre]:
        #                 if not visited[j]: q.append(j)
        #
        #         # cur_height+1，因为把当前层全部遍历完了
        #         cur_height += 1
        #
        #     # visited reset (一定要在continue前面，否则cur_height > min_height时不重置visited了)
        #     visited = [False for _ in range(n)]
        #
        #     if cur_height > min_height: continue
        #     elif cur_height < min_height:
        #         min_height = cur_height
        #         res.clear()
        #     res.append(i)
        #
        # return res
# leetcode submit region end(Prohibit modification and deletion)
