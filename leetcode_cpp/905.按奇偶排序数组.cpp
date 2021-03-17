/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        /**
         * 解法一: 双指针，O(N)
        */
        int target_idx = 0;
        for (int i=0; i<A.size(); i++) {
            if (A[i] % 2 == 0) {
                if (i != target_idx) {
                    int tmp = A[target_idx];
                    A[target_idx] = A[i];
                    A[i] = tmp;
                }
                target_idx++;
            }
        }
        return A;
    }
};
// @lc code=end

