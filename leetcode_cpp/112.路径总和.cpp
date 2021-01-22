/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    // bool dfs(TreeNode* root, int sum, int count) {
    //     count += root->val;

    //     // 叶子节点
    //     if (root->left == nullptr && root->right == nullptr) {
    //         if (count == sum) return true;
    //         else {return false;}
    //     }

    //     // 非叶子节点
    //     if (root->left != nullptr && dfs(root->left, sum, count)) return true;
    //     if (root->right != nullptr && dfs(root->right, sum, count)) return true;
    //     return false;
    // }

    bool hasPathSum(TreeNode* root, int sum) {
        /**
         * 解法一: dfs（其实是回溯）
        */
        // if (root == nullptr) return false;
        // return dfs(root, sum, 0);

        /**
         * 解法二: dfs（更简洁的dfs）
         * 关键点: drilldown时把目标值变为 (sum - root->val) 即可
        */
        if (root == nullptr) return false;
        // 叶子节点
        if (root->left == nullptr && root->right == nullptr) return (sum == root->val);
        return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
    }
};
// @lc code=end

