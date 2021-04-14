# 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。 
# 
#  示例 1: 
# 
#  输入: s = "anagram", t = "nagaram"
# 输出: true
#  
# 
#  示例 2: 
# 
#  输入: s = "rat", t = "car"
# 输出: false 
# 
#  说明: 
# 你可以假设字符串只包含小写字母。 
# 
#  进阶: 
# 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？ 
#  Related Topics 排序 哈希表 
#  👍 251 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # 解法一: 字母排序后进行str比较（O(NlogN)）
        # 解法二: 建立一个hash表，对s和t各过一遍，统计每个字符的出现次数，然后比较字典是否相同（时间O(N),空间O(N)）

        # 解法二（一个hash）: s的元素负责增加count，t的负责减少。看最后hash是否为0
        if len(s) != len(t): return False   # 首先长度不同则返回false
        hash_map = collections.defaultdict(int)     # 不这样写的话，line33当dict里面没有key会报错
        for i in range(len(s)):       # 因为s和t长度相同，所以i能同时取到他俩的元素
            hash_map[s[i]] = hash_map[s[i]] + 1
            hash_map[t[i]] = hash_map[t[i]] - 1

        for i in hash_map.values():
            if i != 0: return False
        return True

        # 解法二（两个hash）
        # hash_c = {}
        # hash_t = {}
        # for c in s:
        #     if c in hash_c.keys():
        #         hash_c[c] += 1
        #     else: hash_c[c] = 1
        #
        # for c in t:
        #     if c in hash_t.keys():
        #         hash_t[c] += 1
        #     else: hash_t[c] = 1
        #
        # return hash_c == hash_t


        # 解法一
        # s = sorted(s)
        # t = sorted(t)
        # return s == t
# leetcode submit region end(Prohibit modification and deletion)
