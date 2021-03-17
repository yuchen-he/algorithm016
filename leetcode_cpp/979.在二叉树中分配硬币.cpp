/*
 * @lc app=leetcode.cn id=979 lang=cpp
 *
 * [979] 在二叉树中分配硬币
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
    int dfs(int &res, TreeNode* root) {
        if (!root) return 0;
        int left_num = dfs(res, root->left);
        int right_num = dfs(res, root->right);
        res += abs(left_num) + abs(right_num);
        return (left_num + right_num + root->val - 1);
    }

    int distributeCoins(TreeNode* root) {
        /**
         * 解法一: 后序遍历。
         * 从叶子节点开始观察“负载数”，然后逐级返回给上层
         * 某节点的"负载数 = 左子树负载数 + 右子树负载数 + node.val - 1(1代表自己需要有1个硬币)
         * 左右子树的负载数的abs之和，即为当前节点的左右子树中需要移动之和（每次都加到res里面，因为向上返回时要返回"负载数"而非”移动数“）
        */
        int res = 0;
        int ret = dfs(res, root);
        return res;
    }
};
// @lc code=end

