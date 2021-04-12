/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int helper(vector<int>& nums, int k) {
        // u: 待替换位置
        // x: 数组的遍历
        // k: 可保留的重复次数
        int u = 0;
        for (auto x: nums) {
            // u < k: nums数组的前k个数字直接保留（因为可以保留k个重复项）
            // nums[u - k]: 待替换位置前k位的元素（作用是计数重复的个数，与解法二的dup类似）
            // x != nums[u - k]: 如果x == nums[u - k]
            if (u < k || x != nums[u - k]) nums[u++] = x;
        }
        return u;
    }

    int removeDuplicates(vector<int>& nums) {
        /**
         * 解法二: 双指针通解（保留K个重复项都通用）
        */
        return helper(nums, 2);       // 如果能保留重复的5项，则传入5

        /**
         * 解法一: 自己想的，用重复次数的计数dup，和待插入位置idx
        */
        // int length = nums.size();
        // if (length == 1) return length;

        // int dup = 0;
        // int insertIdx = 1;
        // for (int i = 1; i < length; i++) {
        //     if (nums[i] == nums[i-1]) {
        //         if (dup == 0) {
        //             // 第一次出现重复 -> 允许
        //             nums[insertIdx++] = nums[i];
        //         }
        //         dup++;
        //     }
        //     else {
        //         nums[insertIdx++] = nums[i];
        //         dup = 0;
        //     }
        // }
        // return insertIdx;
    }
};
// @lc code=end

