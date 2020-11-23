/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // 参考: https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/dai-ma-sui-xiang-lu-chi-tou-qian-zhong-hou-xu-de-d/
        // 与前序不同, 中序遍历是左中右
        // 1. 先访问的是二叉树顶部的节点
        // 2. 然后一层一层向下访问，直到到达树左面的最底部
        // 3. 再开始处理节点(也就是在把节点的数值放进result数组中)，这就造成了处理顺序和访问顺序是不一致的。
        // ===> 需要借用指针的遍历来帮助访问节点，栈则用来处理节点上的元素。
        vector<int> ret;
        stack<TreeNode*> myStack;
        TreeNode* cur = root;

        if (root == NULL) return ret;

        // while要用||，因为最开始栈为空，但cur不为空
        // 当左子树全遍历完并且打印完root时，栈可能为空，但要继续右子树
        while (!myStack.empty() || cur != NULL) {
            if (cur != NULL) {          // 要一直遍历至最左的节点
                myStack.push(cur);
                cur = cur->left;
            }
            else {
                cur = myStack.top();    // 当前栈顶的元素是没有左子树的那个节点
                myStack.pop();
                ret.push_back(cur->val);
                cur = cur->right;       // 当cur没有右子树时，cur会在下一次进入这个else里面时指向top（这个top可能是上上层的根节点，自己画图更好理解）
            }
        }
        return ret;
    }
};
// @lc code=end

