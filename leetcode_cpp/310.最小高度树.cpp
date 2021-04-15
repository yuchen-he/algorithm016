/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // 解析看Python代码
        if (edges.empty()) return {0};
        // 建立邻接表和入度表
        unordered_map<int, vector<int>> adjacent;
        vector<int> inDegree(n, 0);
        for (auto pair: edges) {
            adjacent[pair[0]].push_back(pair[1]);
            adjacent[pair[1]].push_back(pair[0]);
            inDegree[pair[0]]++;
            inDegree[pair[1]]++;
        }

        // 入度为1的都入列
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 1) q.push(i);
        }

        // BFS: 把入度为1的逐个删除，最终剩下的即为可能的根节点
        int count = n;
        int qSize = q.size();
        while (count > 2) {
            count -= qSize;
            for (int k = 0; k < qSize; k++) {
                int cur = q.front();
                q.pop();
                inDegree[cur] = 0;

                for (auto neighbor: adjacent[cur]) {
                    if (inDegree[neighbor] != 0) {
                        inDegree[neighbor]--;
                        if (inDegree[neighbor] == 1) {
                            q.push(neighbor);
                        }
                    }
                }
            }
            qSize = q.size();
        }

        vector<int> res;
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end

