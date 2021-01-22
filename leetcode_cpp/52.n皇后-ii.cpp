/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    void dfs2(int &res, int n, int level, int col, int pie, int la) {
        /**
         * col/pie/col都是位数为n的二进制数
         * col: 表示受列方向的影响，导致的当前行每个位置是否可以放置皇后的二进制表示
         * pie: 表示受主对角方向的影响，导致的当前行每个位置是否可以放置皇后的二进制表示
         * col: 表示受副对角方向的影响，导致的当前行每个位置是否可以放置皇后的二进制表示
        */
        if (level >= n) {
            res++;
            return;
        }

        // 根据上面一层得到的因col/pie/col而得到的可以放皇后的位置，来得到当前层n个位置中可以放的位置
        // 1. 把col/pie/col“与”上再取“非”，得到可以放皇后的位置(标记为1)
        // 2. 因为上面得到的数为32bit，所以需要初始化一个n-bit的全为“1”的二进制数，与上面得到的相“与”
        int bits = ~(col | pie | la) & ((1 << n) - 1);

        // 循环中，每次找到bit的最后一位1，然后drillDown，最后把最后一个1置0以便去找下一个可以放皇后的位置
        while (bits > 0) {
            // 关键点: 怎么pick？
            // 只保留bits的最后一个1，把其他置为0，然后赋值给pick
            // TODO: (x & -x)中的-x（取反）是怎么操作的
            int pick = bits & -bits;

            // 关键点: 放完皇后往下dfs时，怎么改变col/pie/col？
            // col: 把pick中1的位置置1，其他位置就保留上面层积累下来的结果
            // pie: 1. 首先把当前层pick中1的位置置1
            //      2. 因为接下来要去下一层，所以所有为1的位置要往左移动1位
            //         （但是因为在pie中的位置与棋盘中的位置是相反的，所以要右移）
            // la与pie相似
            dfs2(res, n, level+1, col | pick, (pie | pick) >> 1, (la | pick) << 1);

            // 关键点: 把最后一个1置0
            // x&(x-1): 1. 最低位如果是1，减1后就变为了0。与原x按位与后，其他位不发生变化 -> 正好把最后一个1置0
            //          2. 最低位如果是0，就要向高位借位，直到遇到第一个1，它变0，它之后的所有位变1。
            //             与原x按位与后，从刚才的最后一个1开始到最末位就全部为0了 -> 达到了把x最后一个1置0的效果
            bits = bits & (bits - 1);
        }
    }

    void dfs1(int &res, int n, int level, vector<int> col, vector<int> pie, vector<int> la) {
        /**
         * 时间上快不了多少，空间优化了点
         * 不需要track，只需要判断level是否到达n-1
        */
        // Terminator
        if (level >= n) {
            res++;
            return;
        }

        // drill down
        for (int i=0; i<n; i++) {
            // cut
            if (col[i] || pie[i+level] || la[i-level+n-1]) {
                continue;
            }

            // select
            col[i] = 1;
            pie[i+level] = 1;
            la[i-level+n-1] = 1;
            dfs1(res, n, level+1, col, pie, la);

            // reverse (for next i)
            col[i] = 0;
            pie[i+level] = 0;
            la[i-level+n-1] = 0;
        }
    }

    void dfs(int &res, int n, vector<int> track, vector<int> col, vector<int> pie, vector<int> la) {
        // Terminator
        int level = track.size();
        if (level >= n) {
            res++;
            return;
        }

        // drill down
        for (int i=0; i<n; i++) {
            // cut
            if (col[i] || pie[i+level] || la[i-level+n-1]) {
                continue;
            }

            // select
            track.push_back(i);
            col[i] = 1;
            pie[i+level] = 1;
            la[i-level+n-1] = 1;
            dfs(res, n, track, col, pie, la);

            // reverse (for next i)
            track.pop_back();
            col[i] = 0;
            pie[i+level] = 0;
            la[i-level+n-1] = 0;
        }
    }

    int totalNQueens(int n) {
        int res = 0;

        // 解法一: dfs
        // vector<int> track;
        // vector<int> col(n, 0);
        // vector<int> pie(2 * n - 1, 0);
        // vector<int> la(2 * n - 1, 0);

        // // dfs(res, n, track, col, pie, la);
        // dfs1(res, n, 0, col, pie, la);

        // 解法二: 位运算剪枝
        dfs2(res, n, 0, 0, 0, 0);
        return res;
    }
};
// @lc code=end

