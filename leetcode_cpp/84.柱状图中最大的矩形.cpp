/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /**
         * 解法三: 哨兵（解法二改进）
         * 解法二中需要单独考虑的特殊情况: 弹栈的时候，栈为空；遍历完成以后，栈中还有元素；
         * 解决方案: 在输入数组的两端加上两个高度为0的柱形，叫做“哨兵（Sentinel）”
         * 1. 左边的柱形（第1个柱形）由于它一定比输入数组里任何一个元素小，它肯定不会出栈，因此栈一定不会为空；
         * 2. 右边的柱形（第2个柱形）也正是因为它一定比输入数组里任何一个元素小，它会让所有输入数组里的元素出栈（第1个哨兵元素除外）。
        */
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stack<int> st;      
        st.push(0);       // 把第1个高度为0的柱子加进去

        int maxArea = 0;  // 初始化为0即可。而且heihgts=[0]的话，初始化为INT_MIN会出错
        int curArea, curID;
        for (int i = 1; i < heights.size(); i++) {            // 不需要遍历第一个元素
            while (!st.empty() && heights[i] < heights[st.top()]) {
                curID = st.top();
                st.pop();

                // 下面这一步不需要的，因为外层的while循环一样会弹到最左边的与curID相同的元素，然后以i为右边界计算面积，一样能得到需要的最大面积
                // while (heights[curID] == heights[st.top()]) st.pop();
                curArea = (i - st.top() - 1) * heights[curID];
                maxArea = max(curArea, maxArea);
            }
            st.push(i);
        }
        return maxArea;

        /**
         * 解法二: 单调栈 + 遍历。
         * 核心思想: 确定以任何一个柱子为最低高度时，能围成的最大面积 -> 找到它左右边界(第一个高度小于它的柱子)
         * 维护一个单调栈: 栈内保存的是idx，但是idx对应的height是递增的（即栈顶>=它下面的元素），而且idx也是递增的 -> 只当>=前一个高度才入栈
         * 遍历数组，碰到heights[i] < 栈顶元素对应高度时，说明i是其右边界（因为高度比它小），然后利用单调栈找它的左边界即可
         * 遍历完之后栈中还有元素的话，依次取出并确定它对应的面积
        */
        // stack<int> st;
        // int maxArea = INT_MIN;
        // int curArea, curID;
        // int size = heights.size();

        // for (int i = 0; i < size; i++) {
        //     // heights[i] < heights[i-1]
        //     while (!st.empty() && heights[i] < heights[st.top()]) {
        //         // 栈顶元素即为本次要确定面积的idx  ->  右边界为i
        //         curID = st.top();
        //         st.pop();

        //         // 寻找它的左边界 -> 虽然是单调栈，但是有可能有跟它高度相等的位置
        //         while (!st.empty() && heights[curID] == heights[st.top()]) {
        //             // 与curID所在高度相等的idx都不要了（因为他们围成的面积肯定没curID大，因为curID位置在他们的右边）
        //             st.pop();
        //         }
                
        //         // 注意点: 此时有可能栈内没有元素了
        //         // 1. curID对应高度是以它往左的所有柱子的最小的，它左边跟他高度相等的都被pop了
        //         // 2. curID是第一个柱子
        //         if (!st.empty()) {
        //             // 此时st.top()对应的高度小于curID所在位置  ->  st.top()为左边界
        //             curArea = (i - st.top() - 1) * heights[curID];
        //         }
        //         else {
        //             // 注意点: 左边界为-1（即能从idx=0开始到i-1为止取这个宽度）
        //             curArea = i * heights[curID];
        //         }

        //         // 更新最大area
        //         maxArea = max(curArea, maxArea);
        //     }

        //     // 当前的i一定要push，因为只有至少遍历到i+1才能确定它的右边界
        //     st.push(i);
        // }

        // // 此时栈内可能还有元素，且一定是递增的，因为他们每个元素的右边都没有比他高度小的柱子  ->  右边界是数组最右
        // while (!st.empty()) {
        //     // 寻找左边界即可，方法同上
        //     curID = st.top();
        //     st.pop();
        //     while (!st.empty() && heights[curID] == heights[st.top()]) st.pop();
        //     if (!st.empty()) {
        //         curArea = (size - st.top() - 1) * heights[curID];
        //     }
        //     else {
        //         curArea = size * heights[curID];
        //     }
        //     maxArea = max(curArea, maxArea);
        // }

        // return maxArea;

        /* 解法一: 暴力法。把任何两个柱子之间能围成的最大面积都算出来，然后求最大值 -> O(N^2) */
        /**
         * 解法二: dp（错解）
         * 要保存的中间状态: （到当前idx为止能围成的最大面积，最大面积时的起点idx，起点到当前位置的最低柱子高度）
         * 转移方程: max(只用当前idx柱子的面积，把当前柱子与之前的连成一片时的面积)
        */
        // if (heights.size() == 0) return 0;

        // // （最大面积时的起点idx，起点到当前位置的最低柱子高度, 到当前idx为止能围成的最大面积）
        // vector<vector<int>> dp(1, {0, heights[0], heights[0]});
        // for (int i = 1; i < heights.size(); i++) {
        //     int minHeight = min(heights[i], dp[i-1][1]);
        //     int withPre = (i - dp[i-1][0] + 1) * minHeight;
        //     if (withPre >= heights[i]) {    
        //         // 错误。[1,2,2]第一个2时不能选withPre。
        //         // 错误。而且[2,2,5,5]在第一个5肯定会选wiehPre，但其实两个5相连最大。
        //         dp.push_back({dp[i-1][0], minHeight, withPre});
        //     }
        //     else {
        //         dp.push_back({i, heights[i], heights[i]});
        //     }
        // }

        // // 取所有位置时的最大面积
        // int res = INT_MIN;
        // for (int j = 0; j < heights.size(); j++) {
        //     res = max(res, dp[j][2]);
        // }
        // return res;
    }
};
// @lc code=end

