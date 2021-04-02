/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        /**
         * 解法一: dp (https://leetcode-cn.com/problems/edit-distance/solution/zi-di-xiang-shang-he-zi-ding-xiang-xia-by-powcai-3/)
         * 如果word1[i] == word2[j]: dp[i][j] = dp[i-1][j-1] 
         * 如果word1[i] != word2[j]: dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[j-1][i]) + 1
         * 关键点: 
         *     1. dp[i-1][j-1]: 替换。
         *     2. dp[i-1][j]: 删除。(因为dp[i-1][j]已经代表了用word1中~i-1的字母凑成了word2中～j的单词，而[i][j]处多了word1的i字母，把它删除即可)
         *     3. dp[i][j-1]:
         * 对“dp[i-1][j-1] 表示替换操作，dp[i-1][j] 表示删除操作，dp[i][j-1] 表示插入操作。”的补充理解：
         * 以 word1 为 "horse"，word2 为 "ros"，且 dp[5][3] 为例，即要将 word1的前 5 个字符转换为 word2的前 3 个字符，也就是将 horse 转换为 ros，因此有：
         *     (1) dp[i-1][j-1]，即先将 word1 的前 4 个字符 hors 转换为 word2 的前 2 个字符 ro，然后将第五个字符 word1[4]（因为下标基数以 0 开始） 由 e 替换为 s（即替换为 word2 的第三个字符，word2[2]）
         *     (2) dp[i][j-1]，即先将 word1 的前 5 个字符 horse 转换为 word2 的前 2 个字符 ro，然后在末尾补充一个 s，即插入操作
         *     (3) dp[i-1][j]，即先将 word1 的前 4 个字符 hors 转换为 word2 的前 3 个字符 ros，然后删除 word1 的第 5 个字符
        */
        int rows = word1.size(), cols = word2.size();
        vector<int> dp(cols + 1);            // 空字母也加上，所以要rows+1
        int upper_left = 0;                  // dp只用一维数组时，因为需要dp[i-1][j-1]，所以要保存左上角的值

        for (int i = 0; i <= rows; i++) {
            for (int j = 0; j <= cols; j++) {
                if (i == 0) {                // 初始化第一行（用" "去凑word2）
                    dp[j] = j;
                    continue;
                }
                if (j == 0) {                // 初始化第一列（用word1去凑" "）
                    upper_left = dp[j];      // 把上一行的j位置的值保存下来
                    dp[j] = i;
                    continue;
                }

                int tmp = dp[j];             // 把上一行的j位置的值保存下来
                if (word1[i-1] == word2[j-1]) {
                    dp[j] = upper_left;
                }
                else {
                    dp[j] = 1 + min(upper_left, min(dp[j-1], dp[j]));
                }
                upper_left = tmp;            // 更新upper_left
            }
        }
        return dp[cols];
    }
};
// @lc code=end

