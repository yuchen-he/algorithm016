/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
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
    // vector<int> ret;
    vector<int> preorder(Node* root) {
        // 迭代解法(跟二叉树前序遍历的迭代算法一样)
        stack<Node*> st;
        vector<int> res;
        st.push(root);
        while (!st.empty()) {
            Node* temp = st.top();
            st.pop();
            if (temp != NULL) {
                res.push_back(temp->val);
                vector<Node*> temp_ch = temp->children;
                for (int i=temp_ch.size()-1; i>=0; i--) {
                    st.push(temp_ch[i]);
                }
            }
        }
        return res;

        // 递归解法
        // if (root){
        //     ret.push_back(root->val);
        //     if ((root->children).size() != 0){
        //         for(int i=0; i<(root->children).size(); i++){
        //             preorder(root->children[i]);
        //         }
        //     }
        // }
        // return ret;
    }
};
// @lc code=end

