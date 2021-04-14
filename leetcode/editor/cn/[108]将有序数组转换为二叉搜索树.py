# 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。 
# 
#  本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。 
# 
#  示例: 
# 
#  给定有序数组: [-10,-3,0,5,9],
# 
# 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
# 
#       0
#      / \
#    -3   9
#    /   /
#  -10  5
#  
#  Related Topics 树 深度优先搜索 
#  👍 699 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        """
        解法二: 基本同一。但是不需要子函数，直接递归调用sortedArrayToBST（传入子数组）得到左右子节点即可。
        """
        if not nums:
            return None

        mid = len(nums) >> 1
        root = TreeNode(nums[mid])
        root.left = self.sortedArrayToBST(nums[:mid])
        root.right = self.sortedArrayToBST(nums[mid+1:])
        return root

        """
        解法一: 从中间扩散。O(N)
        把当前范围的中点位置设为当前树的根节点，然后左右节点分别利用递归去找（递归时利用数组中的index限定查找范围即可）
        """
        # length = len(nums)
        # if length == 0: return None
        #
        # def dfs(left_idx, right_idx):
        #     mid = (left_idx + right_idx) >> 1
        #     if left_idx <= right_idx and 0 <= mid <= length - 1:
        #         return TreeNode(nums[mid], dfs(left_idx, mid - 1), dfs(mid + 1, right_idx))
        #     else:
        #         return None
        #
        # return dfs(0, length)
# leetcode submit region end(Prohibit modification and deletion)
