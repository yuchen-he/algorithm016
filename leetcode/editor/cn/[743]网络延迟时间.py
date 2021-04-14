# 有 n 个网络节点，标记为 1 到 n。 
# 
#  给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点， w
# i 是一个信号从源节点传递到目标节点的时间。 
# 
#  现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。 
# 
#  
# 
#  示例 1： 
# 
#  
# 
#  
# 输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
# 输出：2
#  
# 
#  示例 2： 
# 
#  
# 输入：times = [[1,2,1]], n = 2, k = 1
# 输出：1
#  
# 
#  示例 3： 
# 
#  
# 输入：times = [[1,2,1]], n = 2, k = 2
# 输出：-1
#  
# 
#  
# 
#  提示： 
# 
#  
#  1 <= k <= n <= 100 
#  1 <= times.length <= 6000 
#  times[i].length == 3 
#  1 <= ui, vi <= n 
#  ui != vi 
#  0 <= wi <= 100 
#  所有 (ui, vi) 对都 互不相同（即，不含重复边） 
#  
#  Related Topics 堆 深度优先搜索 广度优先搜索 图 
#  👍 228 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        """
        解法一: dijkstra 堆优化
        改进点: 不需要每次手动去找未确定最短距离的节点(即!seen[i])中的最小距离点(即dist[i]最小)，
               而是向小顶堆中push候选未确定的点，然后每次取出堆顶元素即可
        """
        # 邻接表用hash_map表示(比二维数组更省空间)
        graph = collections.defaultdict(list)   # 这里要明确value是list（list里面的元素是(cur, dist)的元祖）
        for pre, cur, dist in times:
            graph[pre].append((cur, dist))      # 不能用graph[pre] = [cur, dist]，这样会替换掉之前的

        # 建立一个list，先放入节点k（"优先级"为0，即距k点距离为0）然后用heapq操作它
        pq = [(0, k)]

        # 是否已经确定最短距离
        seen = [False] * (n + 1)

        # 最终确认的距k节点最短距离表
        dist = [math.inf] * (n + 1)
        dist[0] = 0
        dist[k] = 0

        while pq:
            d, node = heapq.heappop(pq)
            # 关键点: 如果node已经被访问过了，就不再访问（优先队列会有这种情况，因为同一个节点可能从不同节点出发的距离不同，从而都放入了pq中）
            if seen[node]: continue
            seen[node] = True

            for child, child_d in graph[node]:
                if seen[child]: continue
                heapq.heappush(pq, (child_d + d, child))
                dist[child] = min(dist[child], child_d + d)

        res = max(dist)
        return -1 if res == math.inf else res

        """
        解法一: 朴素dijkstra
        注意点: 节点名是从1开始的（而非0），所以建立数组时长度为n+1更好
        参考: https://leetcode-cn.com/problems/network-delay-time/solution/dan-yuan-zui-duan-lu-po-su-de-dijkstra-dui-you-hua/
        """

        # # 建立邻接表（朴素dijkstra只需要用数组即可）
        # graph = [[math.inf] * (n + 1) for _ in range(n + 1)]
        # for pre, cur, dis in times:
        #     graph[pre][cur] = dis     # pre -> cur 的距离为dis
        #
        # # 建立距离源点k的最短距离表
        # dist = [math.inf] * (n + 1)
        # dist[0] = 0      # 0位置不使用的（因为节点从1开始）
        # dist[k] = 0      # k节点距离k的长度为0
        #
        # # 建立已确定最短距离的list
        # seen = [False] * (n + 1)
        #
        # # 确保进行n次循环
        # for _ in range(1, n + 1):
        #     minIndex = -1
        #     for i in range(1, n + 1):
        #         if not seen[i] and (minIndex == -1 or dist[i] < dist[minIndex]):
        #             # minIndex在第一个not seen[i]时，会因为minIndex == -1的判断进入这里，然后被赋值为i
        #             # 接下来未确定的节点的距离就会跟dist[minIndex]相比
        #             # => 从而保证所有未确定的节点的dist都会相比，然后取到最小的那个
        #             minIndex = i
        #
        #     # 找到了能确定最短距离的节点
        #     seen[minIndex] = True
        #
        #     # 关键: 更新与该节点minIndex邻接的其他节点t的"暂时"最短距离（因为可能t们可能从其他节点来的路径更短）
        #     for t in range(1, n + 1):
        #         # t有三种情况
        #         # 1. 从当前minIndex无法去到t: dist[t]会是初始状态math.inf，graph[minIndex][t]也是math.inf
        #         # 2. 仍是math.inf: 从未被计算过距离  ->  dist[t]直接用graph[minIndex][t] + dist[minIndex]赋值（因为是距K的距离）
        #         # 3. 是某个数值: 被其他路径计算过  ->  要与当前计算出的距离比较，选择更短的
        #         dist[t] = min(dist[t], graph[minIndex][t] + dist[minIndex])      # 因为dist[t]初始化为inf，所以可以一步到位
        #
        # res = max(dist)
        # return -1 if res == math.inf else res

# leetcode submit region end(Prohibit modification and deletion)
