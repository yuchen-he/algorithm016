/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /**
         * 解法二: dp空间优化，只用两个变量保存中间状态
         * 在解法一中，每次计算dp[i]时，只需要用到dp[i-1]的值
         * 因此，用pre_max, pre_min两个变量来保存dp[i-1][0]和dp[i-1][1]即可。
         * 注意点1: 在更新pre_max和pre_min时，可能会用到当前step更新了的pre_min或pre_max，所以先用cur_min和cur_max保存当前step的状态，再更新pre_max和pre_min
         * 注意点2: 因为最终输出的最大乘积的值是在过程中一直变化的，所以要用一个max_product，且每一个step都更新它。
        */
        // int pre_min, pre_max = nums[0];   // 这样pre_max无法被赋值？？？
        int pre_min = nums[0];
        int pre_max = nums[0];
        int max_product = nums[0];
        int cur_min, cur_max;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] >= 0) {
                cur_min = min(nums[i] * pre_min, nums[i]);
                cur_max = max(nums[i] * pre_max, nums[i]);
            }
            else {
                cur_min = min(nums[i] * pre_max, nums[i]);
                cur_max = max(nums[i] * pre_min, nums[i]);
            }
            // 注意点2: 每次都更新总的最大乘积
            max_product = max(max_product, cur_max);

            // 注意点1: 用cur更新pre
            pre_min = cur_min;
            pre_max = cur_max;
        }
        return max_product;

        /**
         * 解法一: dp, 2维数组保存中间状态
         * dp[i][0]: 以 nums[i] 结尾的连续子数组的最小值
         * dp[i][1]: 以 nums[i] 结尾的连续子数组的最大值
         * 输出: 遍历dp[i][1], 找到里面的最大值即可
         * 注意点1: 最大值和最小值是相互转换的（e.g 当前位置i是负数的话，乘以i-1时的最小值[如果是负]，则立马变成了最大值）
         * 注意点2: nums[i]必须被选取（这一点恰恰好也是使得子数组、子序列问题更加简单的原因：当情况复杂、分类讨论比较多的时候，需要固定一些量，以简化计算）
        */
        // int length = nums.size();
        // vector<vector<int>> dp(length, vector<int>(2, nums[0]));

        // for (int i=1; i<length; i++) {
        //     if (nums[i] >= 0) {
        //         // nums[i] >= 0时，必有(nums[i] * dp[i-1][0]) < (nums[i] * dp[i-1][1])
        //         dp[i][0] = min(nums[i] * dp[i-1][0], nums[i]);  // e.g nums[i]=0, dp[i-1][0]为正，那就不需要把之前加入到子数组中了
        //         dp[i][1] = max(nums[i] * dp[i-1][1], nums[i]);
        //     }
        //     else {
        //         // nums[i] < 0时，必有(nums[i] * dp[i-1][0]) > (nums[i] * dp[i-1][1])
        //         // 关键点: 并且与之前的最小值的乘积 -> dp[i][1]即i位置的最大值
        //         dp[i][0] = min(nums[i] * dp[i-1][1], nums[i]);
        //         dp[i][1] = max(nums[i] * dp[i-1][0], nums[i]);
        //     }
        // }

        // // 只需要在最大值的数组里找最大值
        // int max_product = dp[0][1];
        // for (int i=0; i<length; i++) {
        //     max_product = max(max_product, dp[i][1]);
        // }
        // return max_product;
    }
};
// @lc code=end

