/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        /*
        1. 递归：O(2^n)
        2. 动态规划：O(n)
        */
        vector<int> res{1, 1};
        for (int i=2; i<(n+1); i++) {
            res.push_back((res[i-2]+res[i-1]));
        }
        return res[n];
    }
};
// @lc code=end

