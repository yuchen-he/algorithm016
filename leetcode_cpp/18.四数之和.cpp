/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size()-3; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            // if (nums[i] > 0) break;       # target is not 0
            for (int j=i+1; j<nums.size()-2; j++) {
                // sum three
                int left = j+1;
                int right = nums.size() - 1;
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        // left++, right--
                        // append res
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left-1]) left++;
                        while (left < right && nums[right] == nums[right+1]) right--;
                    }
                    else if (sum < target) {
                        // left++
                        left++;
                    }
                    else {
                        // right--
                        right--;
                    }
                }
            } 
        }
        return res;
    }
};
// @lc code=end

