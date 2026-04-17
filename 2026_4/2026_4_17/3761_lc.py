# 题意
# 给你一个整数数组，找两个下标 i<j，满足 nums[i] 反转后的数等于 nums[j]。
# 在所有这样的“镜像对”里，返回它们下标差的最小值；如果不存在，返回 -1。

class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        last_index = {}
        ans = len(nums)
        # 枚举左边reverse 每个值最大的下标，使用哈希维护
        for i, x in enumerate(nums):
            if x in last_index:
                ans = min(ans, i - last_index[x])
            rev = int(str(x)[::-1])
            last_index[rev] = i
        return ans if ans < len(nums) else -1