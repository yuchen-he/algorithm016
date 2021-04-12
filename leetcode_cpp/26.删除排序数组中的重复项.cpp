/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 不需要删除元素，只需要原数组的前N个元素是不重复的N个元素即可

        // 更快的解法：count累计重复元素的数量，i-count就是下一个应该存放非重复元素的位置了
        int count = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]) count++;
            else nums[i-count] = nums[i];
        }
        return n-count;

        // if (nums.size() == 0) return 0;
        // int j = 1;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i+1] != nums[i]) {
        //         nums[j++] = nums[i+1];
        //     }
        // }
        // return j;
    }
};
// @lc code=end

