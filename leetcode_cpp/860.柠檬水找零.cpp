/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // 简洁方案
        // int five = 0, ten = 0;
        // for (int i : bills) {
        //     if (i == 5) five++;
        //     else if (i == 10) five--, ten++;
        //     else if (ten > 0) ten--, five--;
        //     else five -= 3;
        //     if (five < 0) return false;
        // }

        // 自己手写方案
        int five = 0;
        int ten = 0;
        for (int i=0; i<bills.size(); i++) {
            if (bills[i] == 5) {
                five++;
                continue;
            }
            if (i == 0 && bills[i] != 5) return false;
            // 10
            if (bills[i] == 10) {
                if (five == 0) return false;
                else {
                    ten++;
                    five--;
                    continue;
                }
            }
            // 20
            if (bills[i] == 20) {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                    continue;
                }
                else if (five >= 3) {
                    five = five - 3;
                    continue;
                }
                else {return false;}
            }
        }
        return true;
    }
};
// @lc code=end

