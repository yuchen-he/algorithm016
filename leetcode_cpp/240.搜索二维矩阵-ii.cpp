/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    // bool searchRow(vector<vector<int>>& matrix, int i, int target) {
    //     int left = 0, right = matrix[i].size() - 1;
    //     int mid = 0;
    //     while (left < right) {
    //         int mid = (left + right) >> 1;
    //         if (matrix[i][mid] == target) return true;
    //         else if (matrix[i][mid] < target) {
    //             left = mid + 1;
    //         }
    //         else {
    //             right = mid - 1;
    //         }
    //     }
    //     return (matrix[i][left] == target);
    // }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /**
         * 解法一: 暴力法（按行二分），O(m*logN)
        */
        // int rows = matrix.size(), cols = matrix[0].size();
        // for (int i = 0; i < rows; i++) {
        //     if (target < matrix[i][0] || target > matrix[i][cols-1]) continue;
        //     if (searchRow(matrix, i, target)) return true;
        // }
        // return false;

        /**
         * 解法二: 二分法
         * 从右上角出发，往左都是比当前值小的，往右都是比当前值大的。（相当于排序数组了）
         * 如果target大，则往下移动一个位置（相当于丢弃了当前位置所在行的左边部分）
         * 如果target小，则往左移动一个位置（相当于丢弃了当前位置所在列的下边部分）
        */
        int rows = matrix.size(), cols = matrix[0].size();
        int i = 0, j = cols - 1;
        while (i < rows && j > -1) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) j--;
            else {i++;}
        }
        return false;
    }
};
// @lc code=end

