/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        /**
         * 解法一: "柱状图"解法 + 单调栈 + “哨兵”
         * 1. 计算出矩阵的每个元素的左边连续 1 的数量(包括自身)并保存在leftNum中  ->  这样每一列的对应元素值，就相当于84题柱状图中柱子的高度了
         * 2. 再次遍历每一列，利用“单调栈” + “哨兵”的方法，来计算最大矩形
        */
        if (matrix.size() == 0) return 0;
        int rows = matrix.size(), cols = matrix[0].size();

        // 构建leftNum，每个元素值代表从该位置往左的连续1的个数
        vector<vector<int>> leftNum(rows + 2, vector<int>(cols, -1));
        for (int i = 0; i < rows; i++) {
            leftNum[i+1][0] = matrix[i][0] - '0';
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == '0') leftNum[i+1][j] = 0;
                else {
                    leftNum[i+1][j] = leftNum[i+1][j-1] + 1;
                }
            }
        }

        // 利用单调栈，计算出最大矩阵面积
        int maxArea = 0;
        for (int j = 0; j < cols; j++) {
            stack<int> st;        // 保存的是当前列的index
            st.push(0);           // 把哨兵0的index放入栈中，0对应的leftNum中的值为-1
            for (int i = 1; i < rows + 2; i++) {
                while(!st.empty() && leftNum[i][j] < leftNum[st.top()][j]) {
                    // 说明st.top()对应的index的右边界已经找到了
                    int curID = st.top();
                    st.pop();

                    int curArea = leftNum[curID][j] * (i - st.top() - 1);
                    maxArea = max(maxArea, curArea);
                }
                // 把当前index放进去
                st.push(i);
            }
        }
        return maxArea;
    }
};
// @lc code=end

