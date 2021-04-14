# 给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从 
# JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。 
# 
#  
# 
#  提示： 
# 
#  
#  如果存在多种有效的行程，请你按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序
# 更靠前 
#  所有的机场都用三个大写字母表示（机场代码）。 
#  假定所有机票至少存在一种合理的行程。 
#  所有的机票必须都用一次 且 只能用一次。 
#  
# 
#  
# 
#  示例 1： 
# 
#  输入：[["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
# 输出：["JFK", "MUC", "LHR", "SFO", "SJC"]
#  
# 
#  示例 2： 
# 
#  输入：[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
# 输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
# 解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它自然排序更大更靠后。 
#  Related Topics 深度优先搜索 图 
#  👍 360 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        """
        解法一: DFS回溯(时间复杂度较高)
        参考：https://leetcode-cn.com/problems/reconstruct-itinerary/solution/shou-hua-tu-jie-liang-chong-jie-fa-zui-ji-ben-de-h/
        注意点1: 所有的机票必须都用一次，且只能用一次。
        注意点2: 一个地能飞好几个地时，优先选择字母顺序小的。
        """
        def backtrack(pre, count):
            if count == len(tickets):
                return True                       # 用完了所有机票，返回True给上一层

            for i in range(len(neighbor[pre])):
                # selection
                dest = neighbor[pre][i]
                neighbor[pre].remove(dest)        # 从邻接表中删除选择的目的地
                res.append(dest)

                # drill down
                if backtrack(dest, count + 1):    # 递归下去如果最终返回True了，那就向上继续返回True
                    return True

                # reverse
                neighbor[pre].insert(i, dest)     # 往第i位插回该目的地
                res.pop()

            return False                          # 如果上面没能返回True而到了这里，说明这条路径走不通


        # 建立邻接表
        neighbor = collections.defaultdict(list)  # 如果用普通的{list}，无法给没有的key使用append操作
        for start, end in tickets:
            neighbor[start].append(end)
        for key, value in neighbor.items():
            value.sort()                          # 为了优先选择字母顺序小的

        res = ["JFK"]
        backtrack("JFK", 0)
        return res

        """
        解法二: 欧拉路径
        def backtrack(neighbor, pre):
            while neighbor[pre]:
                # selection
                dest = neighbor[pre].pop(0)       # pop在list首位的目的地（即字母顺序最小的）
                # res.append(dest)                # 不在这里append，改到最后（这样就不用考虑reverse的问题了，因为当前层的res与下一层不一样的）

                # drill down
                backtrack(neighbor, dest)

                # reverse
                # neighbor[pre].append(dest)      # 不在这里
                # res.remove(dest)

            # res.insert(0, pre)                  # 因为是在dfs结束之后添加pre（所以是后序遍历），所以当前层要加在前面
            res.append(pre)                       # 上面改进：先append，最后返回逆序的res

        # 建立邻接表
        neighbor = collections.defaultdict(list)  # 如果用普通的{list}，无法给没有的key使用append操作
        for start, end in tickets:
            neighbor[start].append(end)
        for key, value in neighbor.items():
            value.sort()                          # 为了优先选择字母顺序小的

        res = []
        backtrack(neighbor, "JFK")                # 传入neighbor的话，就不用每层都reverse了
        return res[::-1]
        """
# leetcode submit region end(Prohibit modification and deletion)
