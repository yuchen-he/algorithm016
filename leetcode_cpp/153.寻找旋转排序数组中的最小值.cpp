/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        /**
         * 解法一: 二分法。
         * 有序的一边可以确定最小值。然后更新最小值之后，再去分析无序的一边。
        */
        int left = 0, right = nums.size() - 1;
        int min_val = INT_MAX;

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[left] <= nums[mid]) {             // <=是为了应对left和mid同位置的情况
                min_val = min(nums[left], min_val);
                left = mid + 1;
            }
            else {
                min_val = min(nums[mid], min_val);
                right = mid - 1;
            }
        }
        return min_val;
    }
};
// @lc code=end

