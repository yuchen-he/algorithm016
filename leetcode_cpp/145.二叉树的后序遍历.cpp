/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    // void dfs(vector<int> &res, TreeNode* root) {
    //     //terminator
    //     if (root == nullptr) return;

    //     //drill down
    //     if (root->left != nullptr) dfs(res, root->left);
    //     if (root->right != nullptr) dfs(res, root->right);
    //     res.push_back(root->val);
    // }

    vector<int> postorderTraversal(TreeNode* root) {
        /*
        解法一: dfs
        */
        // vector<int> res;
        // dfs(res, root);
        // return res;

        /**
         * 解法二: 迭代法（利用前序遍历）
        */
        // vector<int> res;
        // stack<TreeNode*> st;
        // if (root != nullptr) st.push(root);

        // // 假前序遍历: 中->右->左（真正的是中左右）
        // while (!st.empty()) {
        //     TreeNode* curr = st.top();
        //     st.pop();
        //     res.push_back(curr->val);
        //     if (curr->left != nullptr) st.push(curr->left);
        //     if (curr->right != nullptr) st.push(curr->right);
        // }

        // reverse(res.begin(), res.end());
        // return res;

        /**
         * 解法三: 迭代法（纯后序遍历方法）
        */
        vector<int> res;
        stack<TreeNode*> st;
        while (!st.empty() || root != nullptr) {
            // 先不放root在st中，在while循环里面先判断root再放入
            if (root != nullptr) {
                st.push(root);
                root = root->left;
            }
            else {
                // 当上一次循环中赋值的root为空时进入这个block
                TreeNode* tmp = st.top();
                if (tmp->right == nullptr) {
                    // 如果栈顶节点的right为空，分两种情况
                    // 1. 第一次判断该节点，该节点确实无右节点
                    // 2. 第二次判断该节点，该节点本来有右节点，但是在之前已经把right压入栈 & 把right改为nullptr了
                    st.pop();
                    res.push_back(tmp->val);
                }
                // 第一次判断该节点，该节点有right时：
                // 1. 令root=right，然后进入下一次循环把它压入栈中
                // 2. 把tmp->right改为NULL，防止之后循环判断成它有right
                root = tmp->right;
                tmp->right = nullptr;
            }
        }
        return res;
    }
};
// @lc code=end

