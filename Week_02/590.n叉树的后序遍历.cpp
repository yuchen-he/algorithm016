/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // void helper(Node* root, vector<int>& res) {
    //     // 与二叉树差不多，只是用一个for循环去遍历children
    //     if (root == NULL) return;
    //     else {
    //         for (int i=0; i<(root->children.size()); i++) {
    //             helper(root->children[i], res);
    //         }
    //         res.push_back(root->val);
    //     }
    // }

    vector<int> postorder(Node* root) {
        // 解法一: 迭代法
        // 1. 前序遍历: 子树的入栈顺序为左->右（真正的前序遍历是右->左）
        // 2. 反转list
        vector<int> res;
        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* temp = st.top();
            st.pop();
            if (temp != NULL) {
                res.push_back(temp->val);
                for (int i=0; i<(temp->children.size()); i++) {
                    st.push(temp->children[i]);
                }
            }
        }

        reverse(res.begin(), res.end());
        return res;

        // 解法二: 递归（for循环中对每个子节点调用本函数）
        // vector<int> res;
        // helper(root, res);
        // return res;
    }
};
// @lc code=end

