/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 */

// @lc code=start
class Solution {
// private:
//     int rows, cols;
public:
    int dfs(vector<vector<int>>& grid, vector<int>& seen, int i, int j) {
        /** 多源BFS: 要求最近/最远距离，而且是有特定点出发的问题，应该用BFS
         * 参考: https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/jian-dan-java-miao-dong-tu-de-bfs-by-sweetiee/
         * 关键点: 从所有陆地"1"开始，"逐层扩散"。
         *        即从原始的陆地开始先向周围海洋扩散一次，然后再从第一次扩散到的所有海洋开始，再扩散一次。(利用队列实现)
         *        最终扩散到的海洋所对应的距离，即为最大的“距最近陆地”的距离
        */

        // 把所有陆地先入列
        int rows = grid.size();
        int cols = grid[0].size();
        queue<vector<int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) q.push({i, j});
            }
        }
        // 注意点: 全0或者全1要返回-1
        if (q.empty() || q.size() == rows * cols) return -1;

        // 扩散时的上下左右索引
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        // 逐层扩散至海洋去
        vector<int> cur(2, NULL);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            int x = cur[0], y = cur[1];

            for (int k = 0; k < 4; k++) {
                int new_x = x + dx[k], new_y = y + dy[k];
                // 如果越界，或者扩散到的是陆地，则不能加入队列
                if (new_x < 0 || new_y < 0 || new_x >= rows || new_y >= cols || grid[new_x][new_y] != 0) continue;

                // 直接改变原来的grid，省得再建立一个同样大小的来保存距离数
                grid[new_x][new_y] = grid[x][y] + 1;
                q.push({new_x, new_y});
            }
        }

        // 此时的x和y，是最后一层扩散到的位置，即它对应的距离是最大的
        // -1是因为初始从1开始扩散时，距离其实是0
        return grid[cur[0]][cur[1]] - 1;

        /** dfs超时了。
        // 1. 越界
        if (i < 0 || j < 0 || i >= rows || j >= grid[0].size()) return (rows + cols - 1);
        // 2. 防止返回去计算上一层的位置，导致无限循环
        if (grid[i][j] == -1) return (rows + cols - 1);
        // 3. "陆地"时，距离为0
        if (grid[i][j] == 1) return 0;

        // drill down
        grid[i][j] = -1;
        int left  = 1 + dfs(grid, seen, i, j - 1);
        int right = 1 + dfs(grid, seen, i, j + 1);
        int up    = 1 + dfs(grid, seen, i - 1, j);
        int down  = 1 + dfs(grid, seen, i + 1, j);
        int minLand = min(min(left, right), min(up, down));
        grid[i][j] = 0;
        return minLand;
    }

    int maxDistance(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<int> seen(rows * cols, -1);
        int maxDist = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                maxDist = max(maxDist, dfs(grid, seen, i, j));
            }
        }
        if (maxDist == 0 || maxDist > (rows + cols - 2)) return -1;
        return maxDist;
    }
    */
};
// @lc code=end

