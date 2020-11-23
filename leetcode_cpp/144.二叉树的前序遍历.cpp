/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    // void helper(TreeNode* root, vector<int>& results) {    // ret需要引用，才能改变preorderTraversal里的ret然后返回
    //     if (root != NULL) {
    //         results.push_back(root->val);
    //         helper(root->left, results);
    //         helper(root->right, results);
    //     }
    //     else {return;}        // return为空，即不return
    // }

    vector<int> preorderTraversal(TreeNode* root) {
        // 解法一: 迭代
        vector<int> ret;
        stack<TreeNode*> myStack;

        if (root != NULL) myStack.push(root);
        else {return ret;}

        while (!myStack.empty()) {
            TreeNode* temp_root = myStack.top();     // 先弹出栈顶，并且把它的val加入ret中
            myStack.pop();
            ret.push_back(temp_root->val);
            if (temp_root->right) myStack.push(temp_root->right);  // 先压左再压右
            if (temp_root->left) myStack.push(temp_root->left);    // 然后下一次while循环时就先pop左并依次押入左的子树
        }

        // 解法二: 递归
        // vector<int> ret;
        // helper(root, ret);

        return ret;
    }
};
// @lc code=end

