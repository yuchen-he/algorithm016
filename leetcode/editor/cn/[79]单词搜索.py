# 给定一个二维网格和一个单词，找出该单词是否存在于网格中。 
# 
#  单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
# 
#  
# 
#  示例: 
# 
#  board =
# [
#   ['A','B','C','E'],
#   ['S','F','C','S'],
#   ['A','D','E','E']
# ]
# 
# 给定 word = "ABCCED", 返回 true
# 给定 word = "SEE", 返回 true
# 给定 word = "ABCB", 返回 false 
# 
#  
# 
#  提示： 
# 
#  
#  board 和 word 中只包含大写和小写英文字母。 
#  1 <= board.length <= 200 
#  1 <= board[i].length <= 200 
#  1 <= word.length <= 10^3 
#  
#  Related Topics 数组 回溯算法 
#  👍 718 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def backtrack(self, board, word, level, i, j) -> bool:
        # terminator
        if i < 0 or j < 0 or i >= len(board) or j >= len(board[0]): return False
        if board[i][j] != word[level]: return False
        if level == len(word) - 1: return True

        # process (如果board[i][j] == word[level])
        board[i][j] = '#'  # 把匹配的位置标记成“已使用”

        # drill down
        if self.backtrack(board, word, level + 1, i - 1, j) or \
                self.backtrack(board, word, level + 1, i + 1, j) or \
                self.backtrack(board, word, level + 1, i, j - 1) or \
                self.backtrack(board, word, level + 1, i, j + 1):
            return True

        # reverse (do we need?)
        board[i][j] = word[level]
        return False

    def exist(self, board: List[List[str]], word: str) -> bool:
        """解法一: 回溯（自己想的, 可以简化代码，看C++代码）
        解法二: 回溯（优化空间，直接修改原board来代表used，看C++代码）
        """
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.backtrack(board, word, 0, i, j): return True
        return False
# leetcode submit region end(Prohibit modification and deletion)
