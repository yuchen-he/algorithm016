/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        /**
         * 螺旋排序数组可以用一个阶跃的图像来帮助理解。
         * 发生旋转的位置左边: 是一条递增直线（在本题中也可能是平行，因为有重复数字）
         * 发生旋转的位置右边: 也是一条递增直线（在本题中也可能是平行，因为有重复数字），并且终点的值<=左边部分的最左边的值
         * 本题中，nums[0]==nums[mid]时，必有nums[size-1]==nums[mid]，因为nums[mid] <= nums[size-1] <= nums[0]
        */
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) return true;
            if (nums[left] == nums[mid]) {    // nums[left]==nums[mid]时，肯定会有nums[right]==nums[mid]，所以只要改一边
                left++;
                continue;
            }
            if (nums[left] < nums[mid]) {     // nums[left] == nums[mid] 不一定有序([1,0,1,1,1])
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
        return false;
    }
};
// @lc code=end

