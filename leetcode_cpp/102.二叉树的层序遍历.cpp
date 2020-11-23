/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    void helper(TreeNode* root, vector<vector<int>>& res, int level) {
        if (root == NULL) return;
        // 当遍历到一个新的深度 level，而最终结果 res 中还没有创建 level 对应的列表时，
        // 应该在 res 中新建一个列表用来保存该 level 的所有节点。
        if (level == res.size()) {
            res.push_back({});
        }
        
        res[level].push_back(root->val);
        if (root->left != NULL) helper(root->left, res, level+1);
        if (root->right != NULL) helper(root->right, res, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 解法二: DFS
        // DFS 不是按照层次遍历的。为了让递归的过程中同一层的节点放到同一个列表中，
        // 在递归时要记录每个节点的深度 level。递归到新节点要把该节点放入 level 对应列表的末尾。
        vector<vector<int>> res;
        helper(root, res, 0);
        return res;

        // 解法一(主要方法): BFS
        // vector<vector<int>> res;
        // if (!root) return res;
        // queue<TreeNode*> q;
        // q.push(root);

        // while (q.size() != 0) {
        //     int pre_len = q.size();
        //     vector<int> layer;
        //     for (int i=0; i<pre_len; i++) {   // 关键：通过当前q的长度，得到上一层的节点总数，然后把他们都pop出来
        //         TreeNode* temp = q.front();
        //         q.pop();
        //         layer.push_back(temp->val);
        //         if (temp->left != NULL) q.push(temp->left);
        //         if (temp->right != NULL) q.push(temp->right);
        //     }
        //     res.push_back(layer);
        // }

        // return res;
    }
};
// @lc code=end

