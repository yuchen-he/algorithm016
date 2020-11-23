/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root, long long val_max, long long val_min) {
        if (root == NULL) return true;
        if (root->val >= val_max || root->val <= val_min) return false;
        // 在递归调用左子树时，我们需要把上界 upper 改为 root.val，因为左子树里所有节点的值均小于它的根节点的值。
        // 同理递归调用右子树时，我们需要把下界 lower 改为 root.val
        return (helper(root->left, root->val, val_min) && helper(root->right, val_max, root->val));
    }
    long long val_min = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        // 解法二: 递归法（非中序遍历）
        // 完全利用【左子树 < root < 右子树】的特性，每次设定上下限
        // return helper(root, LONG_MAX, LONG_MIN);

        // 解法三(最简洁): 递归法（中序遍历），跟正常递归稍有不同，因为没有res.push_back()，而是需要判断true/false
        if (root == NULL) return true;         // 这个true是最核心点，如果是二叉搜索树，这个true会一层层网上传给最终root
        if (!isValidBST(root->left)) return false;      // 关键点：访问左子树。如果左子树的下层节点中有返回false了，那这里就直接返回false给上层节点，否则执行下一行
        if (root->val <= val_min) return false;
        val_min = root->val;
        return isValidBST(root->right);        // 与访问左节点时是一样的意思。只是这里直接用return就行了，因为之后没有process了

        // 解法一: 迭代法，中序遍历（性质: 得到一个升序序列）
        // stack<TreeNode*> st;
        // long long min_val = LONG_MIN;     // 这里必须用LONG_MIN，否则test_case里面会有比INT_MIN更小的数，导致返回false
        // TreeNode* cur = root;
        
        // while (cur != NULL || !st.empty()) {
        //     if (cur != NULL) {
        //         st.push(cur);
        //         cur = cur->left;
        //     }
        //     else {
        //         cur = st.top();
        //         st.pop();
        //         if (cur->val <= min_val) return false;
        //         else {min_val = cur->val;}
        //         cur = cur->right;
        //     }
        // }
        // return true;
    }
};
// @lc code=end

