/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 利用一遍hash表求解（python_code里面先得到dict，再查找，相当于用了两遍）
        map<int, int> a;   //hash表在cpp中用map实现
        vector<int> ret;

        for (int i=0; i<nums.size(); i++) {
            if (a.count(target-nums[i]) > 0) {
                ret.push_back(a[target-nums[i]]);
                ret.push_back(i);
                break;
            }
            /*
            上面的if语句：实际上是在当前i是第二个目标数的时候，去寻找第一个目标数的位置。
            所以下面这句给map添加值的操作在if语句之后。
            如果放在if语句之前，会出现寻找的另一个数是同一个数的情况（虽然可以通过index是否一致来区别开）
            */
            a[nums[i]] = i;
        }
        return ret;
    }
};

// 与官方题解的暴力解法一摸一样
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ret;
//         int n = nums.size();

//         if (n == 0) return ret;
//         for (int i=0; i<(n-1); i++) {
//             for (int j=i+1; j<n; j++) {
//                 if ((nums[i] + nums[j]) == target) {
//                     ret.push_back(i);
//                     ret.push_back(j);
//                     return ret;
//                 }
//             }
//         }
//         return ret;
//     }
// };
// @lc code=end

