/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i=digits.size()-1; i>=0; --i) {
            if (digits[i] != 9) {
                digits[i] = digits[i] + 1;
                return digits;
            }
            else {
                digits[i] = 0;
            }
        }
        
        // digits.insert(digits.begin(), 1);    # 插入的时间复杂度为O(N)
        // 这样操作将是O(1)
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};
// @lc code=end

