/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        int j=1;  //记录下一个非重复元素的保存位置
        for (int i=0; i<(nums.size()-1); i++){
            if (nums[i+1] != nums[i]){
                nums[j++] = nums[i+1];   //j++运算在赋值之后执行(++j会先执行)
            }
        }
        nums.erase((nums.begin()+j), nums.end());
        return nums.size();
    }
};
// @lc code=end

