/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 一次遍历：复杂度同下，但是操作更简洁
        int j = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != 0) {
                if (i != j) {
                    swap(nums[i], nums[j]);        // 使用自带swap函数交换
                }
                j++;     // 在遍历数组时，在没碰到0之前i和j是一起增长的，碰到几个0，i就比j多几
            }
        }
        // 两次遍历：时间O(n), 空间O(1)
        // int j=0;
        // //先把所有非0元素往前挪
        // for(int i=0; i<nums.size(); i++){
        //     if (nums[i]!=0){
        //         nums[j++] = nums[i];
        //     }
        // }
        // //此时j指向的位置是原数组最后一个非0元素现在位置的后一位
        // //所以可以把从j开始到数组长度末尾都置0
        // for(;j<nums.size();j++){
        //     nums[j] = 0;
        // }
    }
};
// @lc code=end

