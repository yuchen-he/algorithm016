/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0, preA = 0;
        int left = 0;
        int right = height.size()-1;
        while (left < right) {
            if (height[left] > height[right]) {
                preA = height[right] * (right - left);
                right--;
            }
            else {
                preA = height[left] * (right - left);
                left++;
            }
            if (preA > maxA) maxA = preA;

            // 用库函数代替(从结果来看时间比较慢)
            // int nowA = min(height[left], height[right]) * (right - left);
            // maxA = max(nowA, maxA);
            // if (height[left] > height[right]) right--;
            // else {left++;}
        }
        return maxA;
    }
};
// @lc code=end

