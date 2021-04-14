# 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。 
# 
#  这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。 
# 
#  示例1: 
# 
#  输入: pattern = "abba", str = "dog cat cat dog"
# 输出: true 
# 
#  示例 2: 
# 
#  输入:pattern = "abba", str = "dog cat cat fish"
# 输出: false 
# 
#  示例 3: 
# 
#  输入: pattern = "aaaa", str = "dog cat cat dog"
# 输出: false 
# 
#  示例 4: 
# 
#  输入: pattern = "abba", str = "dog dog dog dog"
# 输出: false 
# 
#  说明: 
# 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。 
#  Related Topics 哈希表 
#  👍 219 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        """
        解法一: hash_map(p2s) + list
        解法二(C++): 两个hash_map(s2p和p2s) + stringstream(用于挨个处理s中的字符串)
        解法三: 两个hash_map(string_2_int)，p和s都映射到int，在逐个映射的同时把转换后的int值添加到一个list中，然后判断两个list是否相等
        """
        used = []
        m = collections.defaultdict()
        s_list = s.split(' ')
        if len(s_list) != len(pattern): return False

        for i in range(len(pattern)):
            if pattern[i] not in m.keys():
                if s_list[i] not in used:
                    # 当遇到的pattern是新的时，需要保证它对应的值没有被用过，防止pattern = "ab", str = "dog dog"返回true
                    m[pattern[i]] = s_list[i]
                    used.append(s_list[i])
                else:
                    return False
            else:
                if not m[pattern[i]] == s_list[i]:
                    return False
        return True

# leetcode submit region end(Prohibit modification and deletion)
