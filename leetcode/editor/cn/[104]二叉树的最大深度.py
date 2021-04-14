# 给定一个二叉树，找出其最大深度。 
# 
#  二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。 
# 
#  说明: 叶子节点是指没有子节点的节点。 
# 
#  示例： 
# 给定二叉树 [3,9,20,null,null,15,7]， 
# 
#      3
#    / \
#   9  20
#     /  \
#    15   7 
# 
#  返回它的最大深度 3 。 
#  Related Topics 树 深度优先搜索 递归 
#  👍 761 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # def helper(self, cur, depth):
    #     if cur == None:
    #         if depth > self.max_depth:
    #             self.max_depth = depth
    #         return 0
    #     depth += 1
    #     self.helper(cur.left, depth)
    #     self.helper(cur.right, depth)

    def maxDepth(self, root: TreeNode) -> int:
        """解法一: DFS（每到末尾节点更新maxdepth if depth > maxdepth）"""
        # self.max_depth = 0
        # self.helper(root, 0)
        # return self.max_depth

        """解法二: BFS（每层 maxdepth += 1）"""
        if root is None: return 0
        q = [root]
        maxdepth = 0

        while len(q) != 0:
            maxdepth += 1
            cur = []

            while len(q) != 0:
                tmp = q.pop()
                if tmp.right: cur.append(tmp.right)
                if tmp.left: cur.append(tmp.left)

            q = cur
        return maxdepth
# leetcode submit region end(Prohibit modification and deletion)
