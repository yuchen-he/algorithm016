/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    // bool isAnagram(string s, string t) {
    //     if (s.length() != t.length()) return false;
    //     int counts[26] = {0};      //创建一个包含26的元素的数组 -> 模拟a-z
    //     for (int i=0; i<s.size(); i++) {
    //         counts[s[i] - 'a']++;          //关键代码：'z' - 'a' 将会返回字母表中的顺序差
    //         counts[t[i] - 'a']--;
    //     }

    //     for (int j=0; j<26; j++) {
    //         if (counts[j] != 0) return false;
    //     }
    //     return true;
    // }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 解法二: 排序后一次遍历。当遇到异位词时，需要把它加入到它前一个异位词所在的vector中（这个vector在res中）。
        //        因此，维护一个map，使【排序后的词】与【它所在vector在res的index】所对应。
        vector<vector<string>> res;
        unordered_map<string, int> ana_map;          // 用unordered_map时间提升50%以上
        for (int i=0; i<strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (ana_map.count(temp)) {
                res[ana_map[temp]].push_back(strs[i]);   // 关键: 当遇到异位词时，通过map查找它应该添加到的vector在res中的位置
            }
            else {
                ana_map[temp] = res.size();        // 精华: 因为res长度只会在这里改变，所以每新加一个temp，size就加1。
                                                   //       这个temp对应的size值，就是在res中temp所在vector的index。
                vector<string> cur = {strs[i]};
                res.push_back(cur);
            }
        }
        return res;

        // 解法三: 精简版的优秀代码
        // map<string,vector<string> > ma;       // map是【排序后的str】和【它对应的vector】的hash
        // vector<vector<string>> res;
        // for(auto str:strs){
        //     string tmp = str;
        //     sort(tmp.begin(),tmp.end());      // 可改进点：由于全是小写字母，可以自定义一个排序
                                                 // 用一个数组表示26个字母，先把str里的字母个数加进去，然后从a开始把字母加入到tmp中
        //     ma[tmp].push_back(str);
        // }
        // for(auto m:ma)                        // 把map里面的vector全部加入到res即可
        //     res.push_back(m.second);          // m.second是m这个iterator指向位置的value
        // return res;

        // 解法一: 通用解法，双指针i和j(=i+1)  ->  超时了
        // vector<vector<string>> res;
        // if (strs.size() == 0) return res;
        // int length = strs.size();
        // map<int, bool> used;              // 与strs等长的数组，记录使用过了的单词(用下标做标记)
        // for (int i=0; i<strs.size(); i++) {
        //     if (used[i] == true) continue;
        //     vector<string> temp;
        //     temp.push_back(strs[i]);
        //     used[i] = true;
        //     for (int j=i+1; j<strs.size(); j++) {
        //         if (used[j] == true) continue;
        //         if (isAnagram(strs[i], strs[j]) == true) {
        //             temp.push_back(strs[j]);
        //             used[j] = true;
        //         }
        //     }
        //     res.push_back(temp);
        // }
        // return res;
    }
};
// @lc code=end

