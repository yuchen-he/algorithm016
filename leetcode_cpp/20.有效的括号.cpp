/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        // 解法二: 不用hash_map (超级快)
        stack<char> paren;
        for (char& c : s) {
            if (c == '(') paren.push(')');
            else if (c == '[') paren.push(']');
            else if (c == '{') paren.push('}');
            else {
                if (paren.empty() || paren.top() != c) return false; 
                else paren.pop();
            }
        }
        return paren.empty() ;
        // 解法一: hash_map
        // stack<char> temp;
        // map<char, char> ref_map = {{']', '['}, {')', '('}, {'}', '{'}};   // map的初始化
        
        // for (char& c : s) {                       // 对一个string的循环一般这么写
        //     if (c == '(' || c == '[' || c == '{') temp.push(c);
        //     else {
        //         if (temp.empty() || ref_map[c] != temp.top()) return false;
        //         else {temp.pop();}
        //     }
        // }

        // // 下面两行只需要写成这一行
        // return temp.empty();
        // if (temp.empty()) return true;
        // else {return false}
    }
};
// @lc code=end

