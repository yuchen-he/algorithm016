/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> track;
        if (n <= 0 || k<= 0) return res;
        backtrack(n, k, 1, track);
        return res;
    }

    void backtrack(int n, int k, int start_id, vector<int>& track) {
        // 与括号生成有点像，从最开始什么都没有开始一个个添加进来，直到满员
        // Terminator
        if (track.size() == k) {
            res.push_back(track);             // 关键点: 当track.size()满了时，说明这一条路径到底了，把它加进res
            return;
        }

        // Process & Drill down
        for (int i = start_id; i <= n - k + track.size() + 1; i++) {   // 关键点: 剪枝（如果用n-k+1的话，当n=4,k=2时，会导致下面的层永远没法添加4进去（但是我们只需要在第一层不添加4）
            // selection（选择下一条路径）
            track.push_back(i);
            backtrack(n, k, i+1, track);
            // reverse (深度优先遍历有回头的过程，因此递归之前做了什么,即line29的操作，递归之后需要做相同操作的逆向操作)
            // 清扫track，因为是引用，所以需要避免这一条路径的结果在另一条路径里
            track.pop_back();
        }
    }
};
// @lc code=end

