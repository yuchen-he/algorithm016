/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    unordered_map<int, int> m;
    TreeNode* helper(vector<int>& preorder, int p_start, int p_end, vector<int>& inorder, int i_start, int i_end) {
        // terminator
        if (p_start >= p_end || i_start >= i_end) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[p_start]);    // 构造一个有初值的结构体实例
        // root->val = preorder[p_start];
        int mid = m[preorder[p_start]];
        int left_num = mid - i_start;
        root->left = helper(preorder, p_start+1, left_num+p_start+1, inorder, i_start, mid);
        root->right = helper(preorder, left_num+p_start+1, p_end, inorder, mid+1, i_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0; i<inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
// @lc code=end

