/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        // terminator: grid[i][j] == 0
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        
        // grid[i][j] == 1
        // process
        grid[i][j] = 0;
            
        // drill down
        return (1 + dfs(grid, i-1, j) + dfs(grid, i+1, j) + dfs(grid, i, j-1) + dfs(grid, i, j+1));
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        /**
         * 解法一: dfs
        */
        int maxNum = 0;
        int row = grid.size();
        if (row == 0) {return maxNum;}
        int col = grid[0].size();

        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                maxNum = max(maxNum, dfs(grid, i, j));
            }
        }
        return maxNum;
    }
};
// @lc code=end

