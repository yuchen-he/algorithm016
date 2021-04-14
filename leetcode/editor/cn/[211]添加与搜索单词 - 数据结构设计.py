# 请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。 
# 
#  实现词典类 WordDictionary ： 
# 
#  
#  WordDictionary() 初始化词典对象 
#  void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配 
#  bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回 false 。word 中可能包含一些 '
# .' ，每个 . 都可以表示任何一个字母。 
#  
# 
#  
# 
#  示例： 
# 
#  
# 输入：
# ["WordDictionary","addWord","addWord","addWord","search","search","search","se
# arch"]
# [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
# 输出：
# [null,null,null,null,false,true,true,true]
# 
# 解释：
# WordDictionary wordDictionary = new WordDictionary();
# wordDictionary.addWord("bad");
# wordDictionary.addWord("dad");
# wordDictionary.addWord("mad");
# wordDictionary.search("pad"); // return False
# wordDictionary.search("bad"); // return True
# wordDictionary.search(".ad"); // return True
# wordDictionary.search("b.."); // return True
#  
# 
#  
# 
#  提示： 
# 
#  
#  1 <= word.length <= 500 
#  addWord 中的 word 由小写英文字母组成 
#  search 中的 word 由 '.' 或小写英文字母组成 
#  最调用多 50000 次 addWord 和 search 
#  
#  Related Topics 设计 字典树 回溯算法 
#  👍 190 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class WordDictionary:
    """不是循环调用WordDictionary自身，而是循环使用它里面的数据结构Node"""
    class Node:
        def __init__(self):
            self.isEnd = False
            self.child = {}

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = WordDictionary.Node()

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        # 必须要使用cur，用于递归到子节点（而root是这个trie树的头）
        cur = self.root
        for s in word:
            if s not in cur.child:
                # 如果目前trie树中不存在这条分支，那么需要新建这条分支
                cur.child[s] = WordDictionary.Node()
            # 然后cur更新到新建的分支的子节点上，继续向下构建这个word
            cur = cur.child[s]

        # 最终遍历完word之后，把cur所在的子节点记为某个单词的end（cur所在位置可以有子节点，但是它也是某个单词的end，用于之后search）
        if not cur.isEnd:
            cur.isEnd = True


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        return self.backtrack(word, self.root, 0)

    def backtrack(self, word, cur, level) -> bool:
        # terminator: 如果遍历到最后
        # （因为最后一个字母找到之后还会再向下遍历一层，add时也是把最后这个子节点的isEnd设为了True，所以此时level是len(word））
        if level == len(word):
            return cur.isEnd

        # process
        if word[level] != ".":
            # 如果是普通字母
            if word[level] not in cur.child: return False      # 如果不存在这个字母，返回False
            else: return self.backtrack(word, cur.child[word[level]], level + 1)     # 如果存在，则drill down下，并且返回递归的返回值
        else:
            # 如果是"."，则需要遍历尝试当前child中的所有字母，并且递归下去看是否有成立的
            for key in cur.child:
                if self.backtrack(word, cur.child[key], level + 1):
                    return True  # 只要有一个为True，就要返回True
            return False         # 遍历所有都没有返回True，那就返回False




# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
# leetcode submit region end(Prohibit modification and deletion)
