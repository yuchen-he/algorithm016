/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        /**
         * 解法一: 动态规划（回溯算法会超时）
         * 背包问题通解: https://leetcode-cn.com/problems/combination-sum-iv/solution/xi-wang-yong-yi-chong-gui-lu-gao-ding-bei-bao-wen-/
         * 从0～target进行dp
         * dp[target] = 下面的累加和。
         *      使用nums[0]时 : 有dp[target - dp[0]]种组合数
         *      使用nums[1]时 : 有dp[target - dp[1]]种组合数
         *      ...
         *      使用nums[-1]时: 有dp[target - dp[-1]]种组合数
         * 为什么使用nums[0] + dp[target - nums[0]]与nums[2] + dp[target - nums[2]]不怕重合？
         * -> 因为题目说了“顺序不同的序列被视作不同的组合”，所以最后一个元素用的肯定不同，所以不要紧。
         * (518题零钱兑换2: 需要考虑重复的问题)
        */
        sort(nums.begin(), nums.end());
        vector<double> dp(target + 1, 0);
        dp[0] = 1;

        for (int n = 1; n <= target; n++) {
            for (auto k: nums) {
                // 剪枝: k比要凑的n还大
                if (k > n) break;

                dp[n] += dp[n - k];
            }
        }
        return dp[target];
    }
};
// @lc code=end

