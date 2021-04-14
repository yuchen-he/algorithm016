# 给定一个二叉树，返回它的中序 遍历。 
# 
#  示例: 
# 
#  输入: [1,null,2,3]
#    1
#     \
#      2
#     /
#    3
# 
# 输出: [1,3,2] 
# 
#  进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
#  Related Topics 栈 树 哈希表 
#  👍 719 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        # 递归解法(详见cpp代码)
        ret = []
        temp = []
        cur = root

        while cur or temp:
            if cur:
                temp.append(cur)
                cur = cur.left          # 一路向左
            else:
                cur = temp.pop()
                ret.append(cur.val)
                cur = cur.right         # 左没有时：先打印当前的根，然后转到right
                                        #         (right不存在时会在下一次while时转向上上层的根)
        return ret


# leetcode submit region end(Prohibit modification and deletion)
