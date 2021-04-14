# 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。 
# 
#  百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（
# 一个节点也可以是它自己的祖先）。” 
# 
#  例如，给定如下二叉树: root = [3,5,1,6,2,0,8,null,null,7,4] 
# 
#  
# 
#  
# 
#  示例 1: 
# 
#  输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
# 输出: 3
# 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
#  
# 
#  示例 2: 
# 
#  输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
# 输出: 5
# 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
#  
# 
#  
# 
#  说明: 
# 
#  
#  所有节点的值都是唯一的。 
#  p、q 为不同节点且均存在于给定的二叉树中。 
#  
#  Related Topics 树 
#  👍 764 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # 回溯算法: 后序遍历。找到p或q时，就将一层一层往上传递

        # 终止条件: 当前root为空，或者遇到p/q时，返回None或者p/q
        if not root or root == p or root == q: return root

        # 递归执行: 往左右子树遍历，得到返回来的值
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        # 对于当前root节点，它的左右子树返回来的left和right有4种情况
        # 1. l/r均为None，说明这个root不包含p/q，所以它返回None给上层(这时返回left或者right都一样，所以 64，65 行可以这么写)
        #    -> 从而所有非空，非p/q的节点，且不包含p/q的节点均向上返回None
        # 2&3. l和r其中有一个不是None，则返回另一个。
        #    -> 两种情况：(以l为空为例)
        #         第一种: 右子树中包含p或q其中一个，从而返回来的是p或q节点，这种情况将会继续去找下一个
        #         第二种: 右子树中包含p和q，从而返回来的是p和q的公共祖先(在下面层中已经触及到了第4种情况了)
        if not left: return right
        if not right: return left

        # 4. 1/2/3均不满足，即l/r均不为空
        #    -> 说明当前root节点的子左右树中分别包含了p和q，因此这个root为最近公共祖先
        return root
        
# leetcode submit region end(Prohibit modification and deletion)
