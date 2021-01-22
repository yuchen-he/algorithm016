/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie
{
    /** 可以用hash_map或者数组来实现。(数组更快)
     * Trie类里面定义了整个Trie树
     * 1. 首先需要定义一个数据结构，来表示每个节点node的数据
     * 2. 构造函数Trie()，用来初始化root节点(包括节点的数据)
     * 3. 成员函数，用来构建或者修改或者查找trie树
    */
    struct TrieNode // 关键点: 结构体必须定义在public之外，否则报错
    {
        // map<char, TrieNode *> children;
        TrieNode* children[26] = {NULL};  // 这里必须初始化数组，不然下面无法用index来判断是否含有去往下一个节点的指针
        bool isEnd;
        TrieNode() : isEnd(false) {}
        // 关键点: 初始化isEnd为false（也可以TrieNode(bool init): {isEnd = init;};
        // 然后new TrieNode(false)）
    };

private:
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode(); // 关键点: root需要定义在类中，否则成员函数无法调用它
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *curr = root;
        for (char s : word)
        {
            // if (curr->children.count(s) == 0)
            // {
            //     // 如果curr中不存在这个字母，则给该字母(key)赋值一个子TrieNode(value)，表示插入了这个字母
            //     curr->children[s] = new TrieNode();
            // }
            // // // 然后将指针curr指向已赋值完的这个字母指向的节点
            // curr = curr->children[s];
            if (curr->children[s - 'a'] == NULL) {
                curr->children[s - 'a'] = new TrieNode();
            }
            curr = curr->children[s - 'a'];
        }
        curr->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *curr = root;
        for (char s : word)
        {
            // if (curr->children.count(s) == 0)
            // {
            //     return false;
            // }
            // else
            // {
            //     curr = curr->children[s];
            // }
            if (curr->children[s - 'a'] == NULL) {
                return false;
            }
            curr = curr->children[s - 'a'];
        }
        // 如果到达了最末尾，则会返回true，说明word存在。
        return curr->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (char s : prefix)
        {
            // if (curr->children.count(s) == 0)
            // {
            //     return false;
            // }
            // else
            // {
            //     curr = curr->children[s];
            // }
            if (curr->children[s - 'a'] == NULL) {
                return false;
            }
            curr = curr->children[s - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
