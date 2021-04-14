# 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 
# 
#  每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？ 
# 
#  注意：给定 n 是一个正整数。 
# 
#  示例 1： 
# 
#  输入： 2
# 输出： 2
# 解释： 有两种方法可以爬到楼顶。
# 1.  1 阶 + 1 阶
# 2.  2 阶 
# 
#  示例 2： 
# 
#  输入： 3
# 输出： 3
# 解释： 有三种方法可以爬到楼顶。
# 1.  1 阶 + 1 阶 + 1 阶
# 2.  1 阶 + 2 阶
# 3.  2 阶 + 1 阶
#  
#  Related Topics 动态规划 
#  👍 1223 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# 问题分析：由于每次只能走1/2步，所以f(5)=f(3)+f(4), 因为3->5走1步/4->5走2步，没其他方法了，所以最后一走可以忽略 => 斐波拉契数列的第n项求解
# 1. 暴力解法：递归 -> O(2^n)
# 2. hash表法：用一个hash表保存计算过的f(x)，当需要计算它时，如果hash表里有就直接取 -> 还是O(2^n)？
# 3. dp法：创建一个list
class Solution:
    def climbStairs(self, n: int) -> int:
        # dp法
        ret = [1, 1]
        for i in range(2, n+1):
            if i > 1:
                ret.append(ret[i-1] + ret[i-2])

        return ret[n]

        # hash表法
        # hash_map = {1: 1, 2: 2}
        #
        # def helper(n):
        #     if n in hash_map.keys():
        #         return hash_map[n]
        #     else:
        #         ret = helper(n-2) + helper(n-1)
        #         hash_map[n] = ret
        #     return ret
        #
        # return helper(n)
# leetcode submit region end(Prohibit modification and deletion)
