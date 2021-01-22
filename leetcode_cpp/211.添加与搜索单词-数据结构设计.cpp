/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary {
public:
    // WordDictionary* children[26] = {NULL};
    // 或者在构造函数中对数组初始化: memset(children, 0, sizeof(children)); 
    WordDictionary* children[26];
    // bool isEnd = false; 
    bool isEnd;

    /** Initialize your data structure here. */
    WordDictionary() {
        // 分配内存给数组，否则出错
        memset(children, 0, sizeof(children));
        isEnd = false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary* temp = this;
        for (char c: word) {
            if (temp->children[c - 'a'] == NULL) {
                temp->children[c - 'a'] = new WordDictionary();
            }
            temp = temp->children[c - 'a'];
        }
        temp->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return backtrack(word, this, 0);
    }

    bool backtrack(string word, WordDictionary* cur, int level) {
        // 这里可以不用level，每次传word.substr(1, word.size()-1)就可以。（相当于切片）
        //terminator
        if (level == word.size()) {
            return cur->isEnd;
        }
        // if .
        if (word[level] == '.') {
            for (int i=0; i<26; i++) {
                // 剪枝
                if (cur->children[i] != NULL) {
                    // 在递归的参数中做选择，从而不需要在下面撤销选择
                    if (backtrack(word, cur->children[i], level + 1)) return true;
                }
            }
            // 虽然要匹配的是一个点，但是已添加的单词中这个位置没有字母
            return false;
        }
        else {
            if (cur->children[word[level] - 'a'] != NULL) {
                return backtrack(word, cur->children[word[level] - 'a'], level + 1);
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

