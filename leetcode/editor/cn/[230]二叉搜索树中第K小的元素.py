# 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：root = [3,1,4,null,2], k = 1
# 输出：1
#  
# 
#  示例 2： 
# 
#  
# 输入：root = [5,3,6,2,4,null,null,1], k = 3
# 输出：3
#  
# 
#  
# 
#  
# 
#  提示： 
# 
#  
#  树中的节点数为 n 。 
#  1 <= k <= n <= 104 
#  0 <= Node.val <= 104 
#  
# 
#  
# 
#  进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化算法？ 
#  Related Topics 树 二分查找 
#  👍 346 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        """
        解法二: 中序遍历 + 剪枝，O(K)。
        用递归方式的话需要定义全局变量比较麻烦，可以用迭代法解决。
        """
        cur = root
        st = []
        while cur or len(st) != 0:
            if cur is not None:
                st.append(cur)
                cur = cur.left
            else:
                cur = st.pop()

                # 判断当前节点是否是第k大个节点
                if k == 1:
                    return cur.val
                else:
                    k -= 1

                cur = cur.right

        """
        解法一: 中序遍历 O(N)。因为二叉搜索树的中序遍历是从小到大的，然后找第k大元素即可。
        res = []
        def dfs(cur):
            if not cur: return
            if cur.left: dfs(cur.left)
            res.append(cur.val)
            if cur.right: dfs(cur.right)

        dfs(root)
        return res[k - 1]
        """
# leetcode submit region end(Prohibit modification and deletion)
