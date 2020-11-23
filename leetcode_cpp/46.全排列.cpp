/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    void my_tracker(vector<int>& track, vector<int> nums) {
        // terminator
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (find(track.begin(), track.end(), nums[i]) != track.end()) continue;      // 排除重复元素
            track.push_back(nums[i]);
            my_tracker(track, nums);
            track.pop_back();           // 回溯过程: 每回溯一层都清除当前层中在line18中添加的元素
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) return res;
        vector<int> track;
        my_tracker(track, nums);
        return res;
    }
};
// @lc code=end

