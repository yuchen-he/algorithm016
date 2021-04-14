# 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。 
# 
#  
# 
#  示例： 
# 二叉树：[3,9,20,null,null,15,7], 
# 
#      3
#    / \
#   9  20
#     /  \
#    15   7
#  
# 
#  返回其层次遍历结果： 
# 
#  [
#   [3],
#   [9,20],
#   [15,7]
# ]
#  
#  Related Topics 树 广度优先搜索 
#  👍 668 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        # DFS: 与一般的BFS解法不同（BFS比较通用）
        def helper(root, level):
            if not root: return 0
            if level == len(res): res.append([])      # 说明此时是第一次访问到这一个level，所以为这个level在res里创建一个新[]

            res[level].append(root.val)               # 在对应level的list里添加root.val
            if root.left: helper(root.left, level+1)
            if root.right: helper(root.right, level + 1)

        res = []
        helper(root, 0)
        return res
# leetcode submit region end(Prohibit modification and deletion)
