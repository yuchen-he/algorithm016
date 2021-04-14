# 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
# 
#  candidates 中的每个数字在每个组合中只能使用一次。 
# 
#  说明： 
# 
#  
#  所有数字（包括目标数）都是正整数。 
#  解集不能包含重复的组合。 
#  
# 
#  示例 1: 
# 
#  输入: candidates = [10,1,2,7,6,1,5], target = 8,
# 所求解集为:
# [
#   [1, 7],
#   [1, 2, 5],
#   [2, 6],
#   [1, 1, 6]
# ]
#  
# 
#  示例 2: 
# 
#  输入: candidates = [2,5,2,1,2], target = 5,
# 所求解集为:
# [
#   [1,2,2],
#   [5]
# ] 
#  Related Topics 数组 回溯算法 
#  👍 510 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        # 关键点1. 解集不能包含重复的组合 -> 先把candidates排序，每层遍历时从上一层的idx之后开始
        # 关键点2. 排序之后如果有重复数字，依然会出现重复结果。例如[1,1,3]，会得出两个[1,3]的结果
        #    -> 同一level的遍历时，如果跟前一个重复则跳过（不同level可以重复，否则例题的[1,1,6]得不出来）
        def helper(track, start_idx):
            # terminator
            curSum = sum(track)
            if curSum == target:
                res.append(track)
                return

            # process & drill down
            for i in range(start_idx, len(candidates)):
                if i > start_idx and candidates[i] == candidates[i-1]: continue    # 对应关键点2
                if curSum + candidates[i] > target: break        # 因为candidates已经排序了，所以之后的不用再考虑
                helper(track + [candidates[i]], i + 1)   # 与39题的区别（i+1，因为不能重复使用同一元素）

        if not candidates: return []
        candidates.sort()
        res = []
        helper([], 0)
        return res
# leetcode submit region end(Prohibit modification and deletion)
