# 翻转一棵二叉树。 
# 
#  示例： 
# 
#  输入： 
# 
#       4
#    /   \
#   2     7
#  / \   / \
# 1   3 6   9 
# 
#  输出： 
# 
#       4
#    /   \
#   7     2
#  / \   / \
# 9   6 3   1 
# 
#  备注: 
# 这个问题是受到 Max Howell 的 原问题 启发的 ： 
# 
#  谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。 
#  Related Topics 树 
#  👍 776 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        """解法二: 迭代法"""
        if not root: return None
        st = [root]
        while st:
            cur = st.pop()
            cur.left, cur.right = cur.right, cur.left
            if cur.left: st.append(cur.left)
            if cur.right: st.append(cur.right)

        return root

        """解法一: 递归法dfs"""
        # if not root: return None
        # root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
        # return root
# leetcode submit region end(Prohibit modification and deletion)
