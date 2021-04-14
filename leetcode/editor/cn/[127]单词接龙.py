# 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
#  
# 
#  
#  每次转换只能改变一个字母。 
#  转换过程中的中间单词必须是字典中的单词。 
#  
# 
#  说明: 
# 
#  
#  如果不存在这样的转换序列，返回 0。 
#  所有单词具有相同的长度。 
#  所有单词只由小写字母组成。 
#  字典中不存在重复的单词。 
#  你可以假设 beginWord 和 endWord 是非空的，且二者不相同。 
#  
# 
#  示例 1: 
# 
#  输入:
# beginWord = "hit",
# endWord = "cog",
# wordList = ["hot","dot","dog","lot","log","cog"]
# 
# 输出: 5
# 
# 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
#      返回它的长度 5。
#  
# 
#  示例 2: 
# 
#  输入:
# beginWord = "hit"
# endWord = "cog"
# wordList = ["hot","dot","dog","lot","log"]
# 
# 输出: 0
# 
# 解释: endWord "cog" 不在字典中，所以无法进行转换。 
#  Related Topics 广度优先搜索 
#  👍 648 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        # 解法二: 双向BFS
        if len(wordList) == 0 or endWord not in wordList:
            return 0

        beginSet = set()
        endSet = set()
        visited = set(wordList)

        beginSet.add(beginWord)                       # set添加元素方法: add
        endSet.add(endWord)
        visited.remove(endWord)                       # set删除元素方法: remove
        if beginWord in visited:
            visited.remove(beginWord)

        wordLength = len(beginWord)                   # 所有word长度都相同
        step = 1

        while len(beginSet) != 0:
            if len(beginSet) > len(endSet):           # 关键点: 从单词少的set开始向对方扩散（并且把少的设为beginSet）
                beginSet, endSet = endSet, beginSet

            tempSet = set()
            for word in beginSet:
                for i in range(wordLength):
                    tempChar = word[i]
                    for c in string.ascii_lowercase:
                        if c == tempChar:
                            continue
                        word = list(word)             # 关键点: 替换字母不能跟C++一样 word[i] = c
                        word[i] = c
                        word = "".join(word)
                        if word in endSet:            # 在endSet里面，则说明可以扩散过去
                            return step + 1
                        if word in visited:
                            tempSet.add(word)
                            visited.remove(word)
                    word = list(word)                 # 关键点: 复原word（以便去替换下一个位置的字母）
                    word[i] = tempChar
                    word = "".join(word)
            beginSet = tempSet
            step += 1

        return 0

# leetcode submit region end(Prohibit modification and deletion)
