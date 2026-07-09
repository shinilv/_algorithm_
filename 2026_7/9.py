"""
题意：
https://leetcode.cn/problems/path-existence-queries-in-a-graph-i/?envType=daily-question&envId=2026-07-09
思路：
并查集
    p = [i for i in range(n)]

    def find(x):
        if p[x] != x:
            p[x] = find(p[x])
        return p[x]
"""


class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        p = [i for i in range(n)]

        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]
        for i in range(n - 1):
            if abs(nums[i] - nums[i + 1]) <= maxDiff:
                p[find(i)] = find(i + 1)
        ans = []
        for i, j in queries:
            if find(i) == find(j):
                ans.append(True)
            else:
                ans.append(False)
        return ans
