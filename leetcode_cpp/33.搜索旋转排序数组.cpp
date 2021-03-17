/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[left] <= nums[mid]) {                    // 这里的<=是为了应对只剩两个数时，mid和left重复的情况
                // 左边是有序的情况
                if (target >= nums[left] && target < nums[mid]) right = mid - 1;
                else {left = mid + 1;}
            }
            else {
                // 右边是有序的情况
                if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                else {right = mid - 1;}
            }
        }
        return -1;
    }
};
// @lc code=end

