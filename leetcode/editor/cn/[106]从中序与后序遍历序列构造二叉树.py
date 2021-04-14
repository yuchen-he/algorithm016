# 根据一棵树的中序遍历与后序遍历构造二叉树。 
# 
#  注意: 
# 你可以假设树中没有重复的元素。 
# 
#  例如，给出 
# 
#  中序遍历 inorder = [9,3,15,20,7]
# 后序遍历 postorder = [9,15,7,20,3] 
# 
#  返回如下的二叉树： 
# 
#      3
#    / \
#   9  20
#     /  \
#    15   7
#  
#  Related Topics 树 深度优先搜索 数组 
#  👍 448 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        """
        解法一: 后序反转为"假前序"（与105题类似，其实也可以不反转）
        """
        postorder.reverse()
        lookup = {}
        for i in range(len(inorder)):
            lookup[inorder[i]] = i

        def dfs(in_begin, in_end, post_begin, post_end):
            if in_begin > in_end or post_begin > post_end:
                return None

            res = TreeNode(postorder[post_begin])
            mid = lookup[postorder[post_begin]]
            right_num = in_end - mid
            res.left = dfs(in_begin, mid - 1, post_begin + right_num + 1, post_end)
            res.right = dfs(mid + 1, in_end, post_begin + 1, post_begin + right_num)

            return res

        return dfs(0, len(inorder) - 1, 0, len(postorder) - 1)
# leetcode submit region end(Prohibit modification and deletion)
