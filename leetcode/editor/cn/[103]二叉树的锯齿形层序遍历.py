# 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。 
# 
#  例如： 
# 给定二叉树 [3,9,20,null,null,15,7], 
# 
#  
#     3
#    / \
#   9  20
#     /  \
#    15   7
#  
# 
#  返回锯齿形层序遍历如下： 
# 
#  
# [
#   [3],
#   [20,9],
#   [15,7]
# ]
#  
#  Related Topics 栈 树 广度优先搜索 
#  👍 396 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        """
        解法一: BFS，计算层数count，通过判断count的奇偶性来决定往queue中添加顺序（从左添加还是从右添加）
        """
        if not root: return []
        res = []
        q = collections.deque()
        q.append(root)
        count = 0

        while q:
            layer = []
            for _ in range(len(q)):
                pre = q.popleft()
                layer.append(pre.val)
                if pre.left: q.append(pre.left)
                if pre.right: q.append(pre.right)

            if count % 2 == 0: layer.reverse()
            res.append(layer)
            count += 1

        return res

# leetcode submit region end(Prohibit modification and deletion)
