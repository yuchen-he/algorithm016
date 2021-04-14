# 给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。 
# 
#  单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使
# 用。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l"
# ,"v"]], words = ["oath","pea","eat","rain"]
# 输出：["eat","oath"]
#  
# 
#  示例 2： 
# 
#  
# 输入：board = [["a","b"],["c","d"]], words = ["abcb"]
# 输出：[]
#  
# 
#  
# 
#  提示： 
# 
#  
#  m == board.length 
#  n == board[i].length 
#  1 <= m, n <= 12 
#  board[i][j] 是一个小写英文字母 
#  1 <= words.length <= 3 * 104 
#  1 <= words[i].length <= 10 
#  words[i] 由小写英文字母组成 
#  words 中的所有字符串互不相同 
#  
#  Related Topics 字典树 回溯算法 
#  👍 338 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    """
    解法二: Trie树
    时间复杂度: O(M*N) + O(建立前缀树)  与解法一不同，不是嵌套的循环了
    1. 把words里面的单词写进Trie树（Trie树要稍作改进，需要当遍历完某个word之后，把word作为isEnd标志，以便之后可以直接添加到res中）
    2. 从每个位置对图做深度优先搜索
       2.1 路径生成的字符串如果没有在前缀树中出现就提前结束
       2.2 如果到了前缀树中某个单词的结束，就将当前单词加入即可。
    """
    def backtrack(self, board, res, cur, i, j) -> bool:
        # terminator
        if i < 0 or j < 0 or i >= len(board) or j >= len(board[0]): return
        target = board[i][j]
        idx = ord(target) - ord('a')
        if target == '#' or cur.child[idx] == 0: return

        next = cur.child[idx]     # 关键点: 必须要在这里取到next，因为到这一行已经确定board能去到next了，必须在这里添加next.word
        if next.word != "":
            res.append(next.word)
            next.word = ""           # 已经找到了这个word，防止其他路径重复找到它并添加到res，所以置""

        board[i][j] = '#'  # 把匹配的位置标记成“已使用”

        # drill down
        self.backtrack(board, res, next, i - 1, j)
        self.backtrack(board, res, next, i + 1, j)
        self.backtrack(board, res, next, i, j - 1)
        self.backtrack(board, res, next, i, j + 1)

        board[i][j] = target

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        class Trie:
            def __init__(self):
                # 保存: 可以去向的子字母list，用words中的word代替isEnd作为存在某个单词的标志（因为最后需要往res中添加word）
                self.word = ""
                self.child = [0] * 26

        # 建立Trie树
        root = Trie()
        for word in words:
            cur = root
            for char in word:
                idx = ord(char) - ord('a')
                if not cur.child[idx]:
                    cur.child[idx] = Trie()
                cur = cur.child[idx]
            cur.word = word                            # 遍历完某个word之后，把word作为isEnd标志

        # 遍历图
        res = []
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.backtrack(board, res, root, i, j)
        return res


    """
    解法一: 对每个单词都查找一遍（参考79题的解法）
    O(M*N*K*L): K代表单词个数，L代表每个单词的平均长度
    """
    # def backtrack(self, board, word, level, i, j) -> bool:
    #     # terminator
    #     if i < 0 or j < 0 or i >= len(board) or j >= len(board[0]): return False
    #     if board[i][j] != word[level]: return False
    #     if level == len(word) - 1: return True
    #
    #     # process (如果board[i][j] == word[level])
    #     board[i][j] = '#'  # 把匹配的位置标记成“已使用”
    #
    #     # drill down
    #     if self.backtrack(board, word, level + 1, i - 1, j) or \
    #             self.backtrack(board, word, level + 1, i + 1, j) or \
    #             self.backtrack(board, word, level + 1, i, j - 1) or \
    #             self.backtrack(board, word, level + 1, i, j + 1):
    #         board[i][j] = word[level]
    #         return True
    #
    #     # reverse (do we need?)
    #     board[i][j] = word[level]
    #     return False
    #
    # def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
    #     res = set()        # 如果不用set的话，会出现重复添加同一个单词的情况
    #     for i in range(len(board)):
    #         for j in range(len(board[0])):
    #             for word in words:
    #                 if self.backtrack(board, word, 0, i, j):
    #                     res.add(word)
    #     return list(res)
# leetcode submit region end(Prohibit modification and deletion)
