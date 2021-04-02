/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */

// @lc code=start
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        /**
         * 解法一: 从后往前dp。
         * 参考: https://leetcode-cn.com/problems/minimum-cost-for-tickets/solution/java-dong-tai-gui-hua-si-lu-bu-zou-cong-hou-xiang-/
         * 原因: 「今天买多少，得看后几天怎么安排」，即「前面依赖后面」 =>  从后向前来买。
         * 当第i天需要出门旅行时，有下列选择:
         *      1. 买1天票:  那么第i+1天开始是需要自己买票的，因此需要加上i+1天开始的所需最小费用累计（即为dp[i+1]）。
         *      2. 买7天票:  那么第i+7天开始是需要自己买票的，因此需要加上i+7天开始的所需最小费用累计（即为dp[i+1]）。
         *      3. 买30天票: 同上。
         * 从上面3种选择min即可 => dp[i]为第i天开始，所需最小费用累计。
        */
        int length = days.size();
        int maxDay = days[length - 1], minDay = days[0];
        vector<int> dp(maxDay + 31, 0);           // 为了idx与天数对应（dp[0]和dp[>maxDay]的都为0即可）

        for (int i = maxDay, j = length - 1; i >= minDay; i--) {
            // 用j作为判断当前i是否为出行日的idx
            if (days[j] == i) {
                // 出行日
                // 如果i+1/i+7/i+30越界了（因为dp最多只到maxDay），则说明可以当前i买了票就可以管用到最后一天
                dp[i] = min(costs[0] + dp[i + 1], min(costs[1] + dp[i + 7], costs[2] + dp[i + 30]));
                j--;
            }
            else {
                // 非出行日
                dp[i] = dp[i+1];
            }
        }
        return dp[minDay];
    }
};
// @lc code=end

