/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int searchLeft(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)  {
            int mid = (left + right) >> 1;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        if (nums[left] == target) return left;
        else {return -1;}
    }

    int searchRight(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)  {
            int mid = (left + right + 1) >> 1;     // 关键点
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                left = mid;
            }
        }
        if (nums[right] == target) return right;
        else {return -1;}
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if (nums.size() == 0) {return res;}
        
        res[0] = searchLeft(nums, target);
        res[1] = searchRight(nums, target);
        return res;
    }
};
// @lc code=end

