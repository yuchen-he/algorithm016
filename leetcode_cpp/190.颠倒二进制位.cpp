/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        /**
         * n & 1: 取得n的末尾数(0或者1)
         * res << 1: res向左移动一位，右边补一个0
         */
        uint32_t res = 0;
        for (int i=0; i<32; i++) {
            // i < 32: 因为题目已经明确了总共是32位的，且无符号
            res = (res << 1) + (n & 1);
            // 关键点: n >> 1不能改变原本的n，所以要用n = n >> 1
            n = n >> 1;
        }
        return res;
    }
};
// @lc code=end

