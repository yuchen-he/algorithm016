/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
private:
    vector<int> dp;

public:
    NumArray(vector<int>& nums) {
        // 解法一: 初始化时把二维dp[i, j]把i～j的总和保存下来，然后调用sumRange时只需要O(1)复杂度
        //        -> dp[i][j] = dp[i][j-1] + nums[j]
        // 解法二: 只用1维数组保存。调用sumRange时只需dp[right] - dp[left]即可
        int length = nums.size();
        vector<int> tmp(length + 1, 0);       // 优化方案: dp.resize(length + 1);
        dp = tmp;

        for (int i = 1; i <= length; i++) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return (dp[right + 1] - dp[left]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

