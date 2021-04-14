# 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。 
# 
#  找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。 
# 
#  示例: 
# 
#  X X X X
# X O O X
# X X O X
# X O X X
#  
# 
#  运行你的函数后，矩阵变为： 
# 
#  X X X X
# X X X X
# X X X X
# X O X X
#  
# 
#  解释: 
# 
#  被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被
# 填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。 
#  Related Topics 深度优先搜索 广度优先搜索 并查集 
#  👍 473 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        '''
        解法三: 并查集，与解法二相同，从边界的'O'出发，利用并查集将他们连通
        1. 遇到边界的'O': 直接让它与一个dummy相连
        2. 遇到非边界的'O': 让它与上下左右的'O'连成一片
             union相连时应该优先把root设为dummy？（否则跟非边界的'O'相连了就不会跟dummy相连了？）
               -> 不需要，因为dummy也是并查集中增加的一个节点，最终只需要判断某节点是否与dummy拥有同样的root即可，root不一定非得是dummy
        3. 最后: 遍历一遍board，如果当前位置与dummy相连则'O'，否则'X'
        '''
        class UnionFind:
            def __init__(self, count):
                self.parent = [i for i in range(count)]

            def find(self, x):
                root = x
                while self.parent[root] != root:
                    root = self.parent[root]
                while self.parent[x] != x:
                    x, self.parent[x] = self.parent[x], root
                return root

            def union(self, x, y):
                x_p = self.find(x)
                y_p = self.find(y)
                if x_p == y_p:
                    return
                else:
                    # 只需要与dummy进行union时，向y传入dummy，就能控制把其他节点的父节点都弄成dummy
                    self.parent[x_p] = y_p

            def isConnected(self, x, y):
                # 因为第3步要判断是否与dummy相连
                return self.find(x) == self.find(y)

        if not board: return None
        rows = len(board)
        cols = len(board[0])
        dummy = rows * cols      # 关键点: dummy, 是一个在board里面不存在的位置（因为flatten之后最大为rows * cols - 1）
        uf = UnionFind(rows * cols + 1)  # 因为需要增加一个dummy，所以+1
        for i in range(0, rows):
            for j in range(0, cols):
                if board[i][j] == 'O':
                    if i == 0 or i == rows - 1 or j == 0 or j == cols - 1:
                        # 1. 遇到边界的'O': 直接让它与一个dummy相连
                        uf.union(i * cols + j, dummy)
                    else:
                        # 2. 遇到非边界的'O': 让它与上下左右的'O'连成一片（但注意：union相连时应该有限把root设为dummy？）
                        if i > 0 and board[i-1][j] == 'O':
                            uf.union(i * cols + j, (i - 1) * cols + j)
                        if i < rows - 1 and board[i+1][j] == 'O':
                            uf.union(i * cols + j, (i + 1) * cols + j)
                        if j > 0 and board[i][j-1] == 'O':
                            uf.union(i * cols + j, i * cols + j - 1)
                        if j < cols - 1 and board[i][j+1] == 'O':
                            uf.union(i * cols + j, i * cols + j + 1)

        for i in range(0, rows):
            for j in range(0, cols):
                if uf.isConnected(i * cols + j, dummy):
                    board[i][j] = 'O'
                else:
                    board[i][j] = 'X'

        return board
        '''
        解法二: 逆思想dfs，从边界的'O'出发dfs，寻找与之连通的'O'并标记为'#'，最后遍历board即可
        '''
        '''
        if not board: return None
        rows = len(board)
        cols = len(board[0])
        if rows <= 1 or cols <= 1:
            return board

        def dfs(row, col):
            if row < 0 or col < 0 or row >= rows or col >= cols or board[row][col] == 'X' or board[row][col] == '#':
                # 1. 判断是否越界
                # 2. 如果遇到'X'，跳过
                # 3. 如果遇到'#'，说明搜索过了，跳过
                return 0

            # 由于是从边界上的'O'开始出发的，所以遇到的'O'全部置'#'
            board[row][col] = '#'
            dfs(row - 1, col)
            dfs(row + 1, col)
            dfs(row, col - 1)
            dfs(row, col + 1)

        for i in range(0, rows):
            for j in range(0, cols):
                # 关键点: 只有遇到边界上的'O'才开始dfs
                if board[i][j] == 'O' and (i == 0 or i == rows - 1 or j == 0 or j == cols - 1):
                    dfs(i, j)

        # 把标记的'#'复原未'O'，把未标记的'O'改成'X'
        for i in range(0, rows):
            for j in range(0, cols):
                if board[i][j] == '#':
                    board[i][j] = 'O'
                elif board[i][j] == 'O':
                    board[i][j] = 'X'

        return board
        '''

        '''
        解法一(自己想的，但是不通): 直观dfs，寻找'O'，如果与边界联通则不置0.
        难点: 找到'O'时，需先置'X'然后dfs下去，否则会'死递归'。
              但是，如下面情况，会导致第三行的第3个'O'变成'X'但没有被reverse
              [["X","O","X","X"],["X","O","O","X"],["O","X","O","X"],["X","O","X","O"]]
        rows = len(board)
        cols = len(board[0])
        if rows <= 1 or cols <= 1:
            return board

        def dfs(row, col):
            # terminator: if 'X'
            if board[row][col] == 'X': return True

            if board[row][col] == 'O':
                if row == 0 or row == rows - 1 or col == 0 or col == cols - 1:
                    # terminator: if 'O' and (i==0 or i==rows-1 or j==0 or j==cols-1)
                    return False
                else:
                    # drill down: if 'O'
                    board[row][col] = 'X'
                    # if drill down == True
                    if dfs(row - 1, col) and dfs(row + 1, col) and dfs(row, col - 1) and dfs(row, col + 1):
                        return True
                    # else: reverse
                    else:
                        board[row][col] = 'O'
                        return False

        for i in range(1, rows-1):
            for j in range(1, cols-1):
                dfs(i, j)

        return board
        '''
# leetcode submit region end(Prohibit modification and deletion)
