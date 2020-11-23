/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*
        * 思路：
        * 1. 双指针(从前到后)：分别从num1&2开头开始，对num2中每个值找在num1中它的前后值，然后插入
        *    插入这一步的优化：新增一个数组，按顺序把num1&2的元素放入，空间换时间 -> O(m+n)
        * 2. 双指针(从后往前)：不需要额外空间，因为num1已经是m+n长度的数组了(后n位都是0)，所以只需要从大往小放进去即可
        *    (实际需要3指针，分别是num1[m],num2[n]开始，加上一个下一个添加元素的位置，从num1[m+n]开始)
        */
        int p1 = m - 1;
        int p2 = n - 1;
        int p  = m + n - 1;

        while (p2 >= 0) {
            if (p1 < 0) {
                for (int i = 0; i <= p2; i++) {
                    nums1[i] = nums2[i];
                }
                p2 = -1;
            }
            else if (nums1[p1] >= nums2[p2]) {
                nums1[p] = nums1[p1];
                p--;
                p1--;
            }
            else if (nums1[p1] < nums2[p2])
            {
                nums1[p] = nums2[p2];
                p--;
                p2--;
            }
        }
    }
};
// @lc code=end

