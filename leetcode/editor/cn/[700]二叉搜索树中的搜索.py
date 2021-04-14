# 给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。 
# 
#  例如， 
# 
#  
# 给定二叉搜索树:
# 
#         4
#        / \
#       2   7
#      / \
#     1   3
# 
# 和值: 2
#  
# 
#  你应该返回如下子树: 
# 
#  
#       2     
#      / \   
#     1   3
#  
# 
#  在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。 
#  Related Topics 树 
#  👍 111 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        """
        解法一: 因为找到就直接返回节点就行，所以用preorder遍历更好 -> 但是没有用到二叉搜索树的特性
        解法二: 当前root.val与val比较大小，大则只需遍历左子树，否则只需遍历右子树
        """
        if not root or root.val == val: return root
        return self.searchBST(root.left, val) if root.val > val else self.searchBST(root.right, val)

        # def dfs(cur):
        #     if cur.val == val:
        #         return cur
        #
        #     if cur.left:
        #         left = dfs(cur.left)
        #         if left is not None:
        #             return left
        #     if cur.right:
        #         right = dfs(cur.right)
        #         if right is not None:
        #             return right
        #     return None
        #
        # if not root: return None
        # return dfs(root)
# leetcode submit region end(Prohibit modification and deletion)
