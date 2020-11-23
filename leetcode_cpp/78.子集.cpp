/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums, vector<int>& track, int start_id) {
        // terminator
        // if (track.size() == nums.size()) {
            // return;
        // }
        res.push_back(track);       // 不需要上面，直接每次递归都把track加入res里。因为每一次递归处理时都要添加进res

        for (int i = start_id; i < nums.size(); i++) {
            // process (do selection)
            track.push_back(nums[i]);
            // res.push_back(track);    // 转移到line16处理

            // backtrack
            helper(nums, track, i + 1);

            // reverse
            track.pop_back();

            // python处理: 以上3步可以统合成一步（因为没有引用）
            // helper(track+[nums[i]], i+1)       // track+[nums[i]]: 向下传入做选择后的track，但在这一层track没变
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        // res.push_back(track);    // 转移到line16处理
        helper(nums, track, 0);
        return res;
    }
};
// @lc code=end

