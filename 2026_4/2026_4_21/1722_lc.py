"""
题意：在允许的下标交换限制下，重排 source，让它尽量接近 target，求最小不相等位置数。

思路：
把 allowedSwaps 连通块内的元素当作可任意重排，对每个连通块统计 source 和 target 的频次差，
能匹配的尽量匹配，剩下的就是贡献的汉明距离。
"""

class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        n = len(source)
        p = [i for i in range(n)]
        def find(x:int) -> int:
            if x != p[x]:
                p[x] = find(p[x])
            return p[x]
        for a, b in allowedSwaps:
            p[find(a)] = find(b)
        mp1, mp2 = defaultdict(list), defaultdict(list)
        for i in range(n):
            mp1[find(i)].append(source[i])
            mp2[find(i)].append(target[i])
        ans = 0
        for k, arr1 in mp1.items():
            arr2 = mp2[k]
            arr1.sort()
            arr2.sort()
            i, j = 0, 0
            while i < len(arr1) and j < len(arr1):
                if arr1[i] == arr2[j]:
                    ans += 1
                    i += 1
                    j += 1
                elif arr1[i] > arr2[j]:
                    j += 1
                else:
                    i += 1
        return n - ans
            