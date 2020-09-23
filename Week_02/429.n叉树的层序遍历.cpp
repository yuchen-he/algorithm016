/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N叉树的层序遍历
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
    vector<vector<int>> levelOrder(Node* root) {
        // 解法一(自己想出来的~=官方题解一): 队列
        // 先把root放进队列，然后while队列不为空时，一直弹出队列首元素，把它的val加入输出list，把它的所有子节点加入队列。
        // -> 问题: 输出的list虽然是按顺序排列的，但是没有按层分隔开
        // 解决办法: 每次while循环时，记录当前queue的size（这就是上一层的节点总个数）。
        //          然后遍历这个size数量的queue，保存每个节点的val进一个list，并且把每个节点的所有子节点加入queue
        vector<vector<int>> res;
        queue<Node*> q;

        if (root == NULL) return res;
        q.push(root);

        while (q.size() != 0) {
            vector<int> layer_res;               // 用于添加每次while遍历上一层的所有节点的val
            int count = q.size();                // 关键点: 记录当前queue的size，即上一层节点总个数
            for (int i=0; i<count; i++) {        // 遍历count数量的queue元素
                Node* temp = q.front();
                layer_res.push_back(temp->val);
                q.pop();
                for (int j=0; j<(temp->children.size()); j++) {
                    q.push(temp->children[j]);
                }
            }
            res.push_back(layer_res);
        }
        return res;

        // 解法二(自己想出来的=官方题解二): 与解法一基本一致，但是多用了list并且有内存泄漏，导致时间/空间复杂度很高
        // 用一个layer_nodes保存每一层的节点，然后遍历这个layer_nodes
        // 1. 把所有节点的val添加进一个list, 2. 并且把每个节点的子节点都添加到新的layer_nodes里面进行下一次遍历
        // vector<vector<int>> res;
        // vector<Node*> layer_nodes;

        // if (root == NULL) return res;
        // layer_nodes.push_back(root);

        // while (layer_nodes.size() != 0) {
        //     vector<int> layer_res;
        //     vector<Node*> temp_nodes;

        //     for (int i=0; i<layer_nodes.size(); i++) {
        //         layer_res.push_back(layer_nodes[i]->val);
        //         for (int j=0; j<(layer_nodes[i]->children.size()); j++) {
        //             temp_nodes.push_back(layer_nodes[i]->children[j]);
        //         }
        //     }
        //     res.push_back(layer_res);
        //     layer_nodes = temp_nodes;
        // }
        // return res;
    }
};
// @lc code=end

