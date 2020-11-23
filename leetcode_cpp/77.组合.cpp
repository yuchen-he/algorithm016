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
        // 解法一：回溯算法（递归）
        vector<int> track;
        if (n <= 0 || k<= 0) return res;
        backtrack(n, k, 1, track);
        return res;

        // 解法二：回溯算法（迭代法）
        // vector<vector<int>> result;
		// int i = 0;
		// vector<int> p(k, 0);
		// while (i >= 0) {
		// 	p[i]++;
		// 	if (p[i] > n) --i;    # 当下一行的条件满足时，这一行会让最后一位一直加1，并且不断把p加入到res中，直到>n时，回溯到上一层（即p的前一位）
		// 	else if (i == k - 1) result.push_back(p);    # 满了，i保持不变，继续在下一次循环中让p[i]++
		// 	else {
		// 	    ++i;
		// 	    p[i] = p[i - 1];
		// 	}
		// }
		// return result;
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

