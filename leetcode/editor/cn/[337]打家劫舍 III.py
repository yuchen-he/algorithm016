# 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“
# 房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。 
# 
#  计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。 
# 
#  示例 1: 
# 
#  输入: [3,2,3,null,3,null,1]
# 
#      3
#     / \
#    2   3
#     \   \ 
#      3   1
# 
# 输出: 7 
# 解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7. 
# 
#  示例 2: 
# 
#  输入: [3,4,5,1,3,null,1]
# 
#      3
#     / \
#    4   5
#   / \   \ 
#  1   3   1
# 
# 输出: 9
# 解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
#  
#  Related Topics 树 深度优先搜索 
#  👍 737 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        """
        正解: DFS + dp
        1. 当前节点选择不偷时，能偷到的最大钱数 = 左孩子能偷到的钱 + 右孩子能偷到的钱（=max(偷，不偷)，左右孩子不一定偷）
        2. 当前节点选择偷时，能偷到的最大钱数   = 左孩子选择自己不偷时能得到的钱 + 右孩子选择不偷时能得到的钱 + 当前节点的钱数
        综上，需要得到左右孩子分别偷和不偷时的最大钱数，才能计算得到当前节点的最大钱数。
        但当前rob函数只能返回一个值，所以想到要用一个helper函数
        """
        def helper(cur):
            if not cur: return 0, 0

            # 先求出左右孩子分别的偷与不偷的最大钱数
            left_tou, left_butou = helper(cur.left)
            right_tou, right_butou = helper(cur.right)

            # 然后根据dp方程计算当前节点并返回
            butou = max(left_butou, left_tou) + max(right_butou, right_tou)
            tou = cur.val + left_butou + right_butou
            return tou, butou

        if not root: return 0
        tou, butou = helper(root)
        return max(tou, butou)

        """
        错解1：BFS，奇偶层的总和中较多的输出（可以只取第1层和第4层）
        错解2: 根据DP的思想，可以把每一层的总和先用BFS排成数组，然后dp（[2,1,3,null,4]会出错，可以相邻两层取不在同一路径的节点）
        # if not root: return 0
        # dp = []
        #
        # # BFS
        # q = collections.deque()
        # q.append(root)
        # while q:
        #     size = len(q)
        #     curSum = 0
        #     for _ in range(size):
        #         cur = q.popleft()
        #         curSum += cur.val
        #
        #         if cur.left: q.append(cur.left)
        #         if cur.right: q.append(cur.right)
        #
        #     dp.append(curSum)
        #
        # # dp
        # butou, tou = 0, 0
        # for i in range(len(dp)):
        #     butou_new = max(butou, tou)
        #     tou_new = butou + dp[i]
        #     tou = tou_new
        #     butou = butou_new
        #
        # return max(butou, tou)
        """
        
# leetcode submit region end(Prohibit modification and deletion)
