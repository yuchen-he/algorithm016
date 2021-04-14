# 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。 
# 
#  在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表
# 示如果要学习课程 ai 则 必须 先学习课程 bi 。 
# 
#  
#  例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。 
#  
# 
#  请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：numCourses = 2, prerequisites = [[1,0]]
# 输出：true
# 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。 
# 
#  示例 2： 
# 
#  
# 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
# 输出：false
# 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。 
# 
#  
# 
#  提示： 
# 
#  
#  1 <= numCourses <= 105 
#  0 <= prerequisites.length <= 5000 
#  prerequisites[i].length == 2 
#  0 <= ai, bi < numCourses 
#  prerequisites[i] 中的所有课程对 互不相同 
#  
#  Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 
#  👍 711 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        """
        解法二: BFS，利用"入度表"做拓扑排序（参考goodnote）
        入度表: 统计每个节点的入读
        拓扑排序: 判断DAG的法宝
        """
        queue = collections.deque()

        # 建立邻接表
        adjacent = [[] for _ in range(numCourses)]
        # 建立入度表
        inDegree = [0 for _ in range(numCourses)]

        for cur, pre in prerequisites:
            adjacent[pre].append(cur)
            inDegree[cur] += 1     # 入度+1

        # 把入度为0的节点入队
        for i in range(numCourses):
            if inDegree[i] == 0: queue.append(i)

        while queue:
            pre = queue.popleft()
            # 没出队一次，说明访问了1个节点，即上了一门课
            numCourses -= 1
            for cur in adjacent[pre]:
                # 为了"删除"pre这个节点，把它的所有邻接节点的入度都-1（全部减完则代表pre这个节点不存在了）
                inDegree[cur] -= 1
                if inDegree[cur] == 0: queue.append(cur)

        return numCourses == 0


        """
        解法一: DFS，转化为判断"是否是有向无环图DAG".
        先建立一个邻接表，便于之后使用dfs进行遍历。
        flag: 0 -> 没被访问过
              1 -> 在当前路径的drilldown过程中曾被访问过
              2 -> 在其他路径的drilldown过程中曾被访问过
        """
        # def dfs(i, adjacent, flag):
        #     # terminator_1. 在当前路径的drilldown过程中曾被访问过
        #     # terminator_2. 在其他路径的drilldown过程中曾被访问过
        #     if flag[i] == 1: return False
        #     if flag[i] == 2: return True
        #
        #     # 如果没被访问过，那么现在访问该节点，从而把它的flag置1
        #     flag[i] = 1
        #     for j in adjacent[i]:
        #         # drill down: 访问邻接节点
        #         if not dfs(j, adjacent, flag): return False
        #
        #     # reverse。当前节点出发的所有路径都没环，那么需要把其flag改为2，然后去看其他不包含该节点的路径。
        #     flag[i] = 2
        #     return True
        #
        # adjacent = [[] for _ in range(numCourses)]
        # for cur, pre in prerequisites:
        #     # 上完pre这门课，才能上cur
        #     # adjacent[pre]对应的list相当于图中pre这个节点的所有邻接节点
        #     adjacent[pre].append(cur)
        #
        # # flag初始化为0，即全都没被访问过
        # flag = [0 for _ in range(numCourses)]
        #
        # for i in range(numCourses):
        #     # 按顺利以某一课程为头节点，进行dfs
        #     # 如果dfs结果为"是DAG"则返回为True，否则为False
        #     if not dfs(i, adjacent, flag): return False
        # return True
# leetcode submit region end(Prohibit modification and deletion)
