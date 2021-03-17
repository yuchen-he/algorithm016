/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        /**
         * 解法一: 双指针，原地修改数组。O(N)
         * i指向偶数idx，j指向奇数idx。遍历i，如果nums[i]为奇数，则移动j直到nums[j]为偶数，然后交换i和j位置的数。
        */
        // int j = 1;
        // for (int i=0; i<nums.size(); i+=2) {
        //     if (nums[i] % 2 == 1) {
        //         while (nums[j] % 2 == 1) {
        //             j += 2;
        //         }
        //         swap(nums[i], nums[j]);
        //         j += 2;
        //     }
        // }
        // return nums;

        /**
         * 解法二: 开新数组。O(N)
        */
        int n = nums.size();
        vector<int> res(n, 0);
        int even = 0, odd = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0) {
                res[even] = nums[i];
                even += 2;
            }
            else {
                res[odd] = nums[i];
                odd += 2;
            }
        }
        return res;
    }
};
// @lc code=end

