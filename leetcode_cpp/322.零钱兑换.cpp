/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    // void dfs(vector<int>& coins, int amount, int idx, int count, int& res) {
    //     /**
    //      * count: 到目前为止累计用掉的硬币数量
    //      * res: 到目前为止达成总金额时的所需最小硬币数量
    //     */
    //     // 终止条件1: 如果凑成了，则看看总的所需硬币数量是否小于其他方法时的最小数量
    //     if (amount == 0) {
    //         res = min(res, count);
    //         return;
    //     }
    //     // 终止条件2: idx超范围了
    //     if (idx == coins.size()) return;

    //     // drill down
    //     // 对于当前idx的面值，从(相对于amount)的最大可使用数量开始递归
    //     for (int k = amount / coins[idx]; k >= 0 && k + count < res; k--) {
    //         // 如果k的最大值为0，也会进行该循环，即不取当前idx的面值，进入下一个idx
    //         // (k + count < res): 剪枝。如果本轮需要用的硬币数量k加上到目前为止的总需硬币数比res小，则肯定这个不是最优解了
    //         dfs(coins, amount - k * coins[idx], idx + 1, count + k, res);
    //     }
    // }

    int coinChange(vector<int>& coins, int amount) {
        /**
         * 解法一: 暴力回溯(类似贪心) + 剪枝
         * 按面值从大到小先排序。
         * 然后先尝试用最大数量的最大面值，往下递归。
         * 如果碰到无法满足amount了，再回溯上来一张张减少大面值的数量
        */
        // if (amount == 0) return 0;
        // sort(coins.begin(), coins.end());
        // reverse(coins.begin(), coins.end());
        // // 优化版: sort(coins.rbegin(), coins.rend());

        // int res = INT_MAX;
        // dfs(coins, amount, 0, 0, res);
        // return res == INT_MAX ? -1 : res;

        /**
         * 解法二: 动态规划（自底向上的思想）
         * 与一般dp问题不同，这里给定的数组是几种可供选择的面值，而且无顺序关系！！
         * 因此，dp[i]应该是: 凑齐总价值 i 需要的最少硬币个数
         *   -> 例如，对于[1,2,5]，凑成面值为 11 的最少硬币个数可以由以下三者的最小值得到：
         *           1. 凑成面值为 10 的最少硬币个数 + 面值为 1 的这一枚硬币；
         *           2. 凑成面值为 9 的最少硬币个数 + 面值为 2 的这一枚硬币；
         *           3. 凑成面值为 6 的最少硬币个数 + 面值为 5 的这一枚硬币。
         * 状态转移方程: dp[i] = min(dp[i], 1 + dp[i - coins[k]] for k in len(coins) if coins[k] <= amount)
         *   -> 为什么需要dp[i]？
         *          => dp[i]首先初始化为一个不可能的值(例如amount+1)，以防dp[i]是凑不出来的情况
        */
        vector<int> dp(amount + 1, amount + 1);

        // 关键点: dp[0] = 0，即单独一枚硬币如果能够凑出面值时，符合最优子结构，则dp[i]会等于1
        //    => e.g. [1,2,5]求dp[1]时，dp[1] = min(dp[1], 1 + dp[0])
        dp[0] = 0;
        for (int i=1; i<=amount; i++) {
            for (auto coin: coins) {
                if (coin <= i && dp[i - coin] != amount + 1) {
                    // coin <= i: 如果coin比当前需要凑的面值i还大，不需要考虑
                    // dp[i - coin] != amount + 1: 如果dp[i-coin]==amount+1，即凑不到i-coin的钱，所以用coin也凑不到当前i
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
                // 如果任何coin都无法满足上面的if，则dp[i]保持为amount+1，即永远无法凑到这个数值
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};
// @lc code=end

