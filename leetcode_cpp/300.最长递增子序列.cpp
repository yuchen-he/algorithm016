/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /**
         * 解法二: dp法改良。O(nlogn)
         * 参考: https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-2/
         * 解法一中有两个for循环，计算dp的for循环肯定是O(n)无法改变。能否设计dp中保存的状态为一个递增序列，然后用二分查找在0~i中找到dp[index]呢？
         * => 利用一个dp数组，index代表最长子序列长度为(i+1)，index对应value代表长度为(i+1)的最长子序列的最大值。
         * => 返回值即为dp数组最后一个有value的(index+1)
        */
        int length = nums.size();
        vector<int> dp(length, 0);
        int tail = 0;
        for (int i = 0; i < length; i++) {
            int left = 0, right = tail;
            while (left < right) {
                // 二分查找: 找到对应value比nums[i]大的最大index，如果没有比nums[i]大的则最终会有left == right == tail
                int mid = (left + right) >> 1;
                if (dp[mid] < nums[i]) left = mid + 1;
                else {
                    right = mid;
                }
            }
            dp[right] = nums[i];        // 这里用left也一样，因为while循环出来之后left == right
            if (tail == right) tail++;  // 下一次循环的一开始是想把nums[i]添加到dp末尾的（但是二分查找里面可能会把插入位置改变）
        }
        return tail;

        /**
         * 解法一: 暴力dp法。O(N^2)
         * 中间状态的设计: 满足“无后效性”，即让不确定的因素(本题中则是i位置的元素是否选在子序列中)确定下来 => 设计让nums[i]必须被选中（53,152题也一样）
         * 每次计算dp[i]时，遍历0~i-1，找到比nums[i]小的index中dp[index]最大的位置。
         * dp[i] = 1 + dp[index]
        */
        // int length = nums.size();
        // vector<int> dp(length, 1);

        // for (int i = 0; i < length; i++) {
        //     for (int j = 0; j < i; j++) {
        //         if (nums[j] < nums[i]) {
        //             dp[i] = max(dp[i], dp[j] + 1);
        //         }
        //     }
        // }
        // int res = 1;
        // for (int k: dp) {
        //     res = max(res, k);
        // }
        // return res;
    }
};
// @lc code=end

