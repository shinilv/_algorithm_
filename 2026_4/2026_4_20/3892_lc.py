"""
题意：
给你一个循环数组，每次可以把任意位置加一，要求用最少操作让数组里至少出现 k 个严格大于左右相邻元素的峰值；做不到就返回 -1。

思路：
先观察 把第 i 个数变为峰值所需要的代价
cost[i] = max(0, max(nums[i - 1], nums[i + 1]) + 1 - nums[i])
注意到峰值是严格大于两边的数，所以相邻位置不能同时选 
因为cost[i] 一定大于0，所以至少k个，也就是恰好选k个使得总代价最小

由于本题是环形数组，先转化为线性的
这里分两种情况：
1. 不选0， 那就再区间[1, n - 1] 选k 个不相邻位置变为峰值
2. 选0， 那就在区间 [2, n - 1] 选k - 1 个不相邻位置变为峰值
两种情况去min就是答案

注意 k > n / 2的时候返回-1
"""

class Solution:
    def minOperations(self, nums: list[int], k: int) -> int:
        n = len(nums)
        if k > n // 2:
            return -1
        if k == 0:
            return 0
        cost = [0] * n
        for i in range(n):
            cost[i] = max(0, max(nums[(i - 1 + n) % n], nums[(i + 1) % n]) + 1 - nums[i])
        
        def func(l:int, r:int, cnt:int) -> int:
            if cnt == 0:
                return 0
            f = [[[float("inf")] * 2 for _ in range(cnt + 1)] for _ in range(2)]
            f[0][1][1] = cost[l]
            f[0][0][0] = 0
            t = 1
            p = 1 # 用于优化一下常数
            for i in range(l + 1, r + 1):
                p += 1
                for j in range(0, min(cnt + 1, p // 2 + 2)):
                    f[t][j][0] = min(f[t ^ 1][j][1], f[t ^ 1][j][0])
                    if j:
                        f[t][j][1] = f[t ^ 1][j - 1][0] + cost[i]
                t ^= 1
            return min(f[t ^ 1][cnt][0], f[t ^ 1][cnt][1])
        return min(func(1, n - 1, k), func(2, n - 2, k - 1) + cost[0])