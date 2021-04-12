/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
private:
    unordered_map<string, vector<int>> m;
    
public:
    vector<int> diffWaysToCompute(string expression) {
        // 剪枝优化
        // 利用hashmap: 储存“待计算字符串 - 所有可能的计算结果”的映射
        if (m.count(expression) > 0) {
            return m[expression];
        }

        vector<int> res;
        int n = expression.size();
        int flag = 0;
        
        for (int i = 0; i < n; i++) {
            // 如果是运算符，则左右一分为二（分治）
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                // 当前level有符号，说明expression不是单个数
                flag = 1;

                // 左右两边计算的返回值: 是一个vector，因为每边可能有多个计算结果（e.g. 右边3-4*5可能回到得到-5和-17）
                // c++的切片可以用substr方法
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1, n - i - 1));

                // 对于left和right中的每一个值，都是左右两边的可能计算结果，所以要把所有可能性都算出来
                for (int l: left) {
                    for (int r: right) {
                        if (expression[i] == '+') res.push_back(l + r);
                        else if (expression[i] == '-') res.push_back(l - r);
                        else if (expression[i] == '*') res.push_back(l * r);
                    }
                }
            }
        }

        // 如果expression是单个数，则直接返回这个数
        if (flag == 0) {
            res.push_back(stoi(expression));
        }

        // 把expression的所有可能计算结果添加到map中
        m[expression] = res;
        return res;
    }
};
// @lc code=end

