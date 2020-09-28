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
    def helper(self, preorder, p_start, p_end, inorder, i_start, i_end):
        if p_start == p_end:
            return None
        root = TreeNode(preorder[p_start])
        # id_root = inorder.index(preorder[p_start])
        # 解法三: 改进点
        id_root = self.hash_map[preorder[p_start]]
        left_num = id_root - i_start       # 该节点左子树的总节点个数 -> 用于在pre数组中从p_start+1开始截取left_pre数组

        # p_start + left_num + 1 是关键 == left_pre数组的结束位置（见goodnote）
        root.left = self.helper(preorder, p_start+1, p_start+left_num+1, inorder, i_start, id_root)
        root.right = self.helper(preorder, p_start+left_num+1, p_end, inorder, id_root+1, i_end)

        return root

    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        # 解法三: 维护一个inorder的hash_map(每个位置的值和index对应)，从而不用每次遍历inorder去找id_root
        self.hash_map = {}
        for idx, value in enumerate(inorder):
            self.hash_map[value] = idx
        # 解法二: 因为拆分pre和in数组需要耗费计算量，所以不每次拆分他们
        # 精华: 改为传入其原数组，以及left_pre, left_in, right_pre, right_in在原pre和in中的的start和end位置(左闭右开)
        return self.helper(preorder, 0, len(preorder), inorder, 0, len(inorder))

        # 解法一
        # 前序遍历的结果数组中，元素顺序为: root/左子树/右子树
        # 中序遍历的结果数组中，元素顺序为: 左子树/root/右子树
        # 所以找到root即可拆分左右子树，并且得到left_pre, left_in, right_pre, right_in这四个数组
        # 而left_pre[0],right_pre[0]即为上一层根节点的左/右子节点
        # 依此类推即可

        # if len(preorder) == 0:
        #     return None
        #
        # root = TreeNode(preorder[0])
        # id_root = inorder.index(preorder[0])      # 可改进点：O(N),不可避免地每次遍历inorder寻找root所在位置 -> 解法三
        # # left_pre = preorder[1 : ]               # 可改进点：以下四步将耗费不必要的计算时间 -> 解法二
        # # left_in = inorder[: id_root]
        # # right_pre = preorder[(id_root + 1) :]
        # # right_in = inorder[id_root :]
        # root.left = self.buildTree(preorder[1 : (id_root + 1)], inorder[: id_root])
        # root.right = self.buildTree(preorder[(id_root + 1) :], inorder[id_root + 1 :])
        #
        # return root
# leetcode submit region end(Prohibit modification and deletion)
