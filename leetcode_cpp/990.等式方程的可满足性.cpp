/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
class Solution {
private:
    vector<int> parent;
public:
    int find(char i) {
        int cur = i - 'a';
        int root = cur;
        while (root != parent[root]) {
            root = parent[root];
        }

        while (cur != parent[cur]) {
            int tmp = parent[cur];
            parent[cur] = root;
            cur = tmp;
        }
        return root;
    }

    void unionElem(char p, char q) {
        int p_parent = find(p);
        int q_parent = find(q);
        if (p_parent != q_parent) {
            parent[q_parent] = p_parent;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        /**
         * 解法一: 并查集（由==和!=联想到是否连通，从而并查集）
         * 先把==的用并查集的union连接起来，然后逐个判断!=的两个元素的root是否相等，相等则返回false
        */
        // 初始化并查集
        for (int i = 0; i < 26; i++) {
            parent.emplace_back(i);
        }

        vector<string> notEqual;
        for (string s : equations) {
            if (s[1] == '=') {
                // 如果是==，把二者union
                unionElem(s[0], s[3]);
            }
            else {
                // 如果是!=，先保存到notEqual里面
                notEqual.emplace_back(s);
            }
        }

        for (string c : notEqual) {
            // if (parent[c[0] - 'a'] == parent[c[3] - 'a']) return false;         // 不能直接用parent找，因为可能有些位置只指向了上一层的父节点（而非root） -> 应该用find()找
            if (find(c[0]) == find(c[3])) return false;
        }
        return true;
    }
};
// @lc code=end

