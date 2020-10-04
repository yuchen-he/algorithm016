/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> nums, vector<int>& track, vector<bool>& used) {
        // terminator
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // 剪枝对象:
            // 1. 已经用过的位置（同一个track里面）
            if (used[i]) continue;
            // 2. 跟当前层中前一个数数相同的数，分两种情况（重点: 不是同一个track里面，而是同一层）
            //    2.1. nums[i-1]在这个track里没用过: 说明回溯到了同一层，此时接着用num[i]则会与同层用num[i-1]，重复 -> continue
            //    2.2. nums[i-1]在这个track里用过了: 说明此时在num[i-1]的下一层 相等不会重复 -> 应该添加nums[i]
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;   // 关键: !nums[i-1]
            track.push_back(nums[i]);
            used[i] = true;
            helper(nums, track, used);
            track.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // if (nums.size() == 0) return res;
        vector<int> track;
        vector<bool> used(nums.size(), false);    // 用used来表示nums的每个位置是否被用了
        sort(nums.begin(), nums.end());     // 关键：排序之后，剪枝2那里才能只需要和前一个元素比较，否则重复的值可能在别处
        helper(nums, track, used);
        return res;
    }
};
// @lc code=end

