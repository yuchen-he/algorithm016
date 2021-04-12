/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double dfs(double x, long long n) {
        // terminator
        if (n == 0) return 1;

        // 二分查找
        // int left = 1, right = n;
        // int mid = right >> 1;
        // int res = dfs(x, mid);          // 这里错了，res要定义为double
        double res = dfs(x, n / 2);
        // if (right % 2 == 0) {
        //     // 偶数次方时，二分后两边个数相等
        //     return res * res;
        // }
        // else {
        //     // 奇数次方时，二分后右边多一个x
        //     return res * res * x;
        // }
        return n % 2 == 0 ? res * res : res * res * x;
    }

    double myPow(double x, int n) {
        /**
         * 解法一: 二分查找 + 回溯
         * 每次只需要计算半边，然后总的结果等于半边的结果再**2（但如果是奇数的n时，要多乘一个x）
        */
        // if (n < 0) return 1 / dfs(x, -n);
        // else if (n == 0) return 1;
        // else {return dfs(x, n);}
        long long N = n;              // 如果输入n = -2147483648的话，无法用int表示
        return n >= 0 ? dfs(x, N) : 1.0 / dfs(x, -N);
    }
};
// @lc code=end

