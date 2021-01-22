/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        /** 解法二: 递归（与栈异曲同工）
         * 每遇到“[”，就当成一个subproblem递归下去
         * 每遇到“]”，说明遇到subproblem的终止条件了
        */
        /** 解法一: 栈
         * 因为要从内层括号开始处理，所以想到用stack。
         * 遍历整个s
         * 1. 遇到字母: 添加到res尾部
         * 2. 遇到数字: 转换成int，赋值给multi
         * 3. 遇到左括号: 把res和multi成对入栈，并且清空他们的值（关键在于把res和multi成对入栈）
         * 4. 遇到右括号，出栈。
         *    res = 出栈组合的res + 出栈组合的multi * 当前的res
        */

        stack<string> st_str;
        stack<int> st_int;
        string res;
        int multi = 0;

        for (char c: s) {
            if (c >= '0' && c <= '9') {
                // 每个数字在0-9之间，但可能像“152”这样三个连续数字
                multi = (multi * 10) + (c - '0');
            }
            else if (c == '[') {
                st_str.push(res);
                st_int.push(multi);
                res = "";
                multi = 0;
            }
            else if (c == ']') {
                // c++中不能直接把string乘以N次
                string temp = res;
                for (int i=0; i<(st_int.top()-1); i++) {
                    res = res + temp;
                }
                res = st_str.top() + res;
                st_str.pop();
                st_int.pop();
            }
            else {
                // 判断是否是字母: 'a' <= c <= 'z'
                res = res + c;
            }
        }

        return res;
    }
};
// @lc code=end

