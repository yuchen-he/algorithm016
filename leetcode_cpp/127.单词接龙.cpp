/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /**
         * 解法一: 单向BFS。
         * 但是与二叉树不同的是，不需要记录每一层的节点个数，因为只要每次出列队首元素，当到达endWord时即为最短路径了。
         * 不是回溯。因为并不需要回退功能，对于当前层的每一条可行的路，这条路走到endWord就返回steps / 无路可走就删除就行了。
         * 单词替换方法: 对于midWord中的每一个位置，都把它换成26个字母试试，如果换过之后的单词在wordList中则把该单词放进queue
        **/
        // 如果endWord不在list里面，那直接返回0
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        // 建立一个queue，里面包含当前词midWord，和到达这个词时的步数step
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        // 为了避免直接修改原始wordList，创建一个新的wordList，用set更好，避免重复(或者unordered_set)
        set<string> newWordList;
        for(auto &i: wordList) newWordList.insert(i);                       // set的插入操作: insert()

        while(!q.empty()) {
            // 如果要出列的是endWord，那返回它的step
            if (q.front().first == endWord) {return q.front().second;}
            
            // 否则就取得当前midWord，然后把它从队列中弹出
            string midWord = q.front().first;
            int step = q.front().second;
            q.pop();

            // 对于midWord中的每一个位置，都把它换成26个字母试试，如果换过之后的单词在wordList中则把该单词放进queue
            for (int i=0; i<midWord.size(); i++) {
                char ch = midWord[i];                                       // 关键点: 保存位置i的原始字母，方便下面去重和复原使用
                for (char c='a'; c<='z'; c++) {
                    // 如果跟现在想换的midWord的字母相同，则跳过
                    if (ch == c) continue;
                    midWord[i] = c;
                    if (newWordList.find(midWord) != newWordList.end()) {   // set的查找操作: find()，形参只需要待查找元素。(不跟std::find查找vector时一样)
                        q.push({midWord, step + 1});
                        newWordList.erase(midWord);                         // set删除操作: erase()
                    }
                // reverse，为了下一次更换字母不受之前更换的影响
                midWord[i] = ch;
                }
            }
        }
        // 队列空了，说明查找不下去了
        return 0;
    }
};
// @lc code=end

