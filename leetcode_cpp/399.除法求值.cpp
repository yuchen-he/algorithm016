/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class Solution {
private:
    unordered_map<string, vector<string, double>> parent;
    void unionElem(string a, string b, double v) {
        // 如果之前没添加进来，则先初始化
        if (parent.count(a) == 0) parent[a] = {a, 1};
        if (parent.count(b) == 0) parent[b] = {b, 1};

        // 如果a和b的祖先不相同，则union他们
        vector<string, double> parent_a = find(a);
        vector<string, double> parent_b = find(b);
        if (parent_a[0] != parent_b[0]) {
            parent[parent_a[0]] = {parent_b[0], v / parent_a[1]};
        }
    }

    vector<string, double> find(string x) {
        // 必须要把x和root直接相连，否则无法建立他俩之间的除法关系
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        /**
         * 解法一: 并查集
        */
        for (int i = 0; i < equations.size(); i++) {
            // 建立并查集
            string a = equations[i][0], b = equations[i][1];
            unionElem(a, b, values[i]);
        }

        vector<double> res;
        for (vector<string> q : queries) {
            if (q[0] == q[1]) res.push_back(1);
            if (parent.count(q[0]) == 0 || parent.count(q[1]) == 0) res.push_back(-1);


        }

        return res;
    }
};
// @lc code=end

