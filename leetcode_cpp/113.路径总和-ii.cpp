/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void backtrack(TreeNode* root, vector<vector<int>>& res, vector<int>& track, int sum) {
        /**
         * vector<int>& track，通过引用进行加速。
         * 注意点: 为了防止回溯时不干扰其他分支，要进行状态的reverse
        */
        if (root == nullptr) return;
        track.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == sum) {
                res.push_back(track);
            }
            // reverse
            track.pop_back();
            return;
        }
        else {
            backtrack(root->left, res, track, sum - root->val);
            backtrack(root->right, res, track, sum - root->val);
            // reverse
            track.pop_back();
        }
    }
    // void backtrack_slow(TreeNode* root, vector<vector<int>>& res, vector<int> track, int sum) {
    //     // terminator
    //     // 上一层的节点
    //     if (root == nullptr) return;

    //     // 处理当前层逻辑
    //     track.push_back(root->val);
        
    //     // drill down
    //     if (root->left == nullptr && root->right == nullptr) {
    //         // 叶子节点
    //         if (root->val == sum) {
    //             res.push_back(track);
    //         }
    //         // 无论如何都要返回，因为没有子节点了
    //         return;
    //     }
    //     else {
    //         // 非叶子节点
    //         if (root->left != nullptr) backtrack(root->left, res, track, sum - root->val);
    //         if (root->right != nullptr) backtrack(root->right, res, track, sum - root->val);
    //     }
    // }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> track;
        backtrack(root, res, track, sum);
        return res;
    }
};
// @lc code=end

