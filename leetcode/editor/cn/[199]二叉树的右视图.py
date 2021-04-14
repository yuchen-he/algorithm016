# 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。 
# 
#  示例: 
# 
#  输入: [1,2,3,null,5,null,4]
# 输出: [1, 3, 4]
# 解释:
# 
#    1            <---
#  /   \
# 2     3         <---
#  \     \
#   5     4       <---
#  
#  Related Topics 树 深度优先搜索 广度优先搜索 递归 队列 
#  👍 410 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        # 解法二: DFS (中->右->左的层序遍历)
        # 解法一: BFS
        # 利用层序遍历，只记录每层的最右边节点val即可
        if not root: return []
        res = []
        q = collections.deque()
        q.append(root)

        while q:
            size = len(q)
            for i in range(size):
                cur = q.popleft()
                if i == size - 1:          # 与普通层序遍历的区别，只需要记录每层最右边
                    res.append(cur.val)
                if cur.left: q.append(cur.left)
                if cur.right: q.append(cur.right)
        return res
# leetcode submit region end(Prohibit modification and deletion)
