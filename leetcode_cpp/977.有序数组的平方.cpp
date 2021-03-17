/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /**
         * 解法一: 首尾双指针
        */
        int n = nums.size();
        vector<int> res(n);

        int left = 0, right = n - 1, k = n - 1;
        while (left <= right) {
            int left_num = nums[left] * nums[left];
            int right_num = nums[right] * nums[right];
            if (left_num > right_num) {
                res[k] = left_num;
                left++;
            }
            else {
                res[k] = right_num;
                right--;
            }
            k--;
        }
        return res;
    }
};
// @lc code=end

