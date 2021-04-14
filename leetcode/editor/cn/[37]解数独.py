# 编写一个程序，通过填充空格来解决数独问题。 
# 
#  一个数独的解法需遵循如下规则： 
# 
#  
#  数字 1-9 在每一行只能出现一次。 
#  数字 1-9 在每一列只能出现一次。 
#  数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。 
#  
# 
#  空白格用 '.' 表示。 
# 
#  
# 
#  一个数独。 
# 
#  
# 
#  答案被标成红色。 
# 
#  提示： 
# 
#  
#  给定的数独序列只包含数字 1-9 和字符 '.' 。 
#  你可以假设给定的数独只有唯一解。 
#  给定数独永远是 9x9 形式的。 
#  
#  Related Topics 哈希表 回溯算法 
#  👍 686 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row = [[0] * 9 for _ in range(9)]
        col = [[0] * 9 for _ in range(9)]
        box = [[0] * 9 for _ in range(9)]        # 这里其实也可以用一个3*3*9的matrix来做(从而避免那个公式)
        # 用set能更优化时间
        # row = [set(range(1, 10)) for _ in range(9)]

        # trick: 保存未填数字的格子，这样回溯过程中的level就可以以是否到达un_used的末尾来定，并且不需要排除已填的格子
        # 不用的情况在C++代码: drilldown时会出现每次j+1会出现j超出范围的情况，这种可以在backtrack的开头terminator进行判断并修改i,j
        un_used = []
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    val = int(board[i][j])
                    row[i][val - 1] = 1
                    col[j][val - 1] = 1
                    box[(i // 3) * 3 + j // 3][val - 1] = 1
                else:
                    un_used.append([i, j])

        def backtrack(index):
            # terminator
            if iter == len(un_used):
                return True

            # drill down
            # trick: board[i][j]一定是'.'
            i, j = un_used[index]
            for k in range(1, 10):
                if row[i][k-1] or col[j][k-1] or box[(i//3) * 3 + j//3][k-1]:
                    continue
                row[i][k-1] = 1
                col[j][k-1] = 1
                box[(i//3) * 3 + j//3][k-1] = 1
                board[i][j] = str(k)
                if backtrack(index + 1):
                    return True
                # reverse
                row[i][k-1] = 0
                col[j][k-1] = 0
                box[(i//3) * 3 + j//3][k-1] = 0
            return False
        backtrack(0)

# leetcode submit region end(Prohibit modification and deletion)
