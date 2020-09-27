# 根据一棵树的前序遍历与中序遍历构造二叉树。 
# 
#  注意: 
# 你可以假设树中没有重复的元素。 
# 
#  例如，给出 
# 
#  前序遍历 preorder = [3,9,20,15,7]
# 中序遍历 inorder = [9,3,15,20,7] 
# 
#  返回如下的二叉树： 
# 
#      3
#    / \
#   9  20
#     /  \
#    15   7 
#  Related Topics 树 深度优先搜索 数组 
#  👍 693 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if len(preorder) == 0:
            return None

        root = TreeNode(preorder[0])
        id_root = inorder.index(preorder[0])      # O(N)？
        # left_pre = preorder[1 : ]
        # left_in = inorder[: id_root]
        # right_pre = preorder[(id_root + 1) :]
        # right_in = inorder[id_root :]
        root.left = self.buildTree(preorder[1 : (id_root + 1)], inorder[: id_root])
        root.right = self.buildTree(preorder[(id_root + 1) :], inorder[id_root + 1 :])

        return root
# leetcode submit region end(Prohibit modification and deletion)
