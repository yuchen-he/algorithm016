/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 解法一:
        int max_dist = 0;
        int far = nums.size()-1;
        for (int i=0; i<far; i++) {
            if (i > max_dist) return false;
            if (i + nums[i] > max_dist) max_dist = i + nums[i];
            // if (max_dist >= nums.size()-1) return true;
        }
        return max_dist >= far;
        // 解法二: 反向查找
        // int goal = nums.size() - 1;
        // for (int i = nums.size() - 2; i >= 0; i--) {
        //     // 如果当前位置能跳到goal，就把goal更新到当前位置
        //     if (i + nums[i] >= goal) goal = i;
        // }
        // // 如果最后的goal是0，说明我们可以跳到最后
        // return goal == 0;
    }
};
// @lc code=end

