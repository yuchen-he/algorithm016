/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 解法二: 更简洁
        // vector<int> dp(col,0);
        // dp[0]=1;                         // 把起点先赋值为1
        // for(int i=0;i<row;i++) {
        //     for(int j=0;j<col;j++) {
        //         if(obstacleGrid[i][j])
        //             // 关键点：j==0时，如果不是障碍物，就维持上一次的dp[j]不变。如果碰到障碍物，那dp[j]=0
        //             dp[j]=0;
        //         else if(j>0)             // 关键点：非障碍物时，只有j>0才会更新
        //             // i==0时，dp[j]为0，所以dp[j]更新后的值就是dp[j-1]，从而只要有障碍物，这一行之后的dp就全是0了
        //             dp[j] += dp[j-1];
        //     }
        // }

        // 解法一(自己想的): dp，空间复杂度O(N)
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<int> dp(col, 0);

        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                // i == 0
                if (i == 0) {
                    // 因为第一行初始值设为了0，所以一旦碰到1(即障碍物)，那dp[j:]以后的全为0(无法走到)，所以不需要再遍历了，直接break
                    if (obstacleGrid[i][j] == 1) break;
                    else {dp[j] = 1;}
                }
                else {
                    // i != 0 && j == 0
                    if (j == 0) {
                        // 由于只用1维数组保存，所以只能看到上一行的dp。
                        // 所以当"点[i][j]为障碍物"，或者"上一行的该列对应dp为0"时，当前位置的dp就该为0
                        if (obstacleGrid[i][j] == 1 || dp[j] == 0) dp[j] = 0;    
                        else {dp[j] = 1;}
                    }
                    else { // i != 0 && j != 0
                        if (obstacleGrid[i][j] == 1) dp[j] = 0;
                        else {
                            dp[j] = dp[j] + dp[j-1];
                        }
                    }
                }
            }
        }
        return dp[col-1];
    }
};
// @lc code=end

