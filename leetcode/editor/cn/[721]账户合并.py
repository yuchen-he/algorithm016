# 给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称 (name)，其
# 余元素是 emails 表示该账户的邮箱地址。 
# 
#  现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为
# 人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。 
# 
#  合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按字符 ASCII 顺序排列的邮箱地址。账户本身可以以任意顺序返回。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：
# accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnn
# ybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Ma
# ry", "mary@mail.com"]]
# 输出：
# [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  
# ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
# 解释：
# 第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。 
# 第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
# 可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
# ['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的
# 。
#  
# 
#  
# 
#  提示： 
# 
#  
#  accounts的长度将在[1，1000]的范围内。 
#  accounts[i]的长度将在[1，10]的范围内。 
#  accounts[i][j]的长度将在[1，30]的范围内。 
#  
#  Related Topics 深度优先搜索 并查集 
#  👍 234 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        """
        解法一: 并查集
        1. 如何转换为并查集问题？
           1.1 accounts中的每一个账户名对应并查集数组中的一个idx（中间过程一直使用idx，最后输出时通过idx去accounts中找账户名即可）
           1.2 建立一个map（格式：<邮箱，账户idx>），用于保存邮箱与账户idx的对应关系，以便之后查到相同邮箱时可以去合并账户
           1.3 遍历每个账户下面的邮箱
                1.3.1 如果map中出现过这个邮箱，说明当前账户跟之前账户是同一个人，那么在并查集里union对应idx
                1.3.2 如果map中没出现过这个邮箱，则添加进map即可
        2. 上面就已经建立好了邮箱与账户idx（这里的idx还包含并查集中子节点的idx，在下一步中更改）的对应
        3. 建立一个新map（账户idx，[邮箱列表]），然后遍历之前的map，把这个新map填满。（这里的idx要调用find找到union过后的parent_idx）
        4. 然后遍历新map，把idx转换到账户名，添加到res中即可（添加前要把账户名的列表sort一下）
        """
        class UnionFind:
            def __init__(self, n=0):
                self.parent = [i for i in range(n)]

            def find(self, x):
                root = x
                while self.parent[root] != root:
                    root = self.parent[root]

                # 剪枝
                while self.parent[x] != x:
                    self.parent[x], x = root, self.parent[x]

                return root

            def union(self, x, y):
                x_p = self.find(x)
                y_p = self.find(y)
                if x_p != y_p:
                    self.parent[x_p] = y_p
                else:
                    return

        # 1.1 建立并查集
        uf = UnionFind(len(accounts))

        # 1.2 accounts -> user
        a2u = collections.defaultdict()

        # 1.3
        for i in range(len(accounts)):
            for j in range(1, len(accounts[i])):
                acc_name = accounts[i][j]
                if acc_name in a2u.keys():
                    # 1.3.1 这里只union，不把a2u中的idx修改成parent[idx]
                    uf.union(i, a2u[acc_name])
                else:
                    # 1.3.2
                    a2u[acc_name] = i

        # 3
        uid2a = collections.defaultdict(list)        # 因为value是一个账户列表
        for acc_name, uid in a2u.items():
            parent_uid = uf.find(uid)
            uid2a[parent_uid].append(acc_name)

        # 4
        res = []
        for k, v in uid2a.items():
            v.sort()                                 # 因为要按字母顺序输出账户名
            cur = [accounts[k][0]]
            cur.extend(v)
            res.append(cur)

        return res
        
# leetcode submit region end(Prohibit modification and deletion)
