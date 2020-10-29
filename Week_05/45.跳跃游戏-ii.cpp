/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        // 自己想的是dp法，会超时 -> O(N^2)
        int step = 0;
        int step_end = 0;
        int max_dist = 0;

        for (int i=0; i<nums.size()-1; i++) {        // 只到倒数第二个位置，以防算出的step多了一步
            if (i + nums[i] > max_dist) max_dist = i + nums[i];
            if (i == step_end) {
                step++;
                step_end = max_dist;
            }
            if (step_end >= nums.size()-1) break;
        }

        return step;
    }
};
// @lc code=end

