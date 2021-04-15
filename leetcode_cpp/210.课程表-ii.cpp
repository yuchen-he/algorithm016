/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 详解见python代码
        // 建立邻接表和入度表
        unordered_map<int, vector<int>> adjacent;
        vector<int> inDegree(numCourses, 0);
        for (auto p: prerequisites) {
            adjacent[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }

        // 把入度为0的课程入队
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        // 把队列中的课程出列，表示可以上这一门课，同时把与其相邻的课程的入度-1
        int count = numCourses;
        vector<int> res;
        while (!q.empty()) {
            int pre = q.front();
            q.pop();

            res.push_back(pre);
            count--;

            for (int neighbor: adjacent[pre]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (count == 0) return res;
        else {return {};}
    }
};
// @lc code=end

