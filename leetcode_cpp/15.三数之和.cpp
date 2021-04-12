/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
        * 1. 排序
        * 2. for循环(a):遇到跟前一个值相同的话跳过（去重）
        *               如果a>0,则结束循环（因为b,c都大于a）
        * 3. 双指针(b, c):左右夹逼，左(a后一位开始)，右(最后开始)，同样遇到相同值跳过（去重）
        */
        sort(nums.begin(), nums.end());          //对vector使用sort函数时，需指定前后端点
        vector<vector<int>> ret;
        if (nums.size() < 3) return ret;

        for (int i=0; i<(nums.size()-2); i++) {
            int b = i + 1;
            int c = nums.size() - 1;

            if (nums[i] > 0) break;                             // 剪枝1
            if ((i > 0) && (nums[i] == nums[i-1])) continue;    // 剪枝2
            while (b < c) {
                int sum_three = nums[i] + nums[b] + nums[c];
                if (sum_three == 0) {
                    ret.push_back(vector<int>{nums[i], nums[b], nums[c]});
                    // 找到不代表结束，还要继续找其他的组合
                    b++;
                    c--;
                    while (b < c && nums[b] == nums[b-1]) b++;
                    while (b < c && nums[c] == nums[c+1]) c--;
                }
                else if (sum_three < 0)
                {
                    b++;
                    // while (b < c && nums[b] == nums[b-1]) b++;     //这两个地方是sum不等于0的情况，所以不用去重
                }
                else {
                    c--;
                    // while (b < c && nums[c] == nums[c+1]) c--;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

