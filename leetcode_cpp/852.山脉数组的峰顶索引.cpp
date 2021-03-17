/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        /**
         * 解法一: 二分法。
         * 找到mid，不与begin/end比，而是与mid-1和mid+1比，从而确定它是在上坡还是下坡
        */
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = (left + right) >> 1;
            
            // 注意 mid == 0时，mid - 1会越界，但是可以确定最大index一定是1
            if (mid == 0) return 1;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                // 找到峰顶的情况
                return mid;
            }
            else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) {
                // 上坡的情况
                left = mid + 1;
            }
            else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                // 下坡的情况
                right = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

