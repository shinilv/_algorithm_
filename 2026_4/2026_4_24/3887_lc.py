"""
题意：给你一个初始无边图，按顺序尝试加入每条边；只有当加入这条边后，
图中所有环的边权和仍然都是偶数时，才真正加入。最后返回成功加入的边数。

思路：
权值只能是0 / 1，疑惑和 = (权值和) % 2
异或和为0的时候，表示和是偶数，
"""

class UnionFind:
    def __init__(self, n:int):
        self.fa = list(range(n))
        self.dis = [0] * n
    def find(self, x:int) -> int:
        fa = self.fa
        if fa[x] != x:
            root = self.find(fa[x])
            self.dis[x] ^= self.dis[fa[x]]
            fa[x] = root
        return fa[x]
    def merge(self, a:int, b:int, v:int) -> bool:
        x, y = self.find(a), self.find(b)
        if x == y:
            return self.dis[a] ^ self.dis[b] == v
        self.dis[x] = self.dis[a] ^ self.dis[b] ^ v
        self.fa[x] = y
        return True

class Solution:
    def numberOfEdgesAdded(self, n: int, edges: List[List[int]]) -> int:
        uf = UnionFind(n)
        ans = 0
        for x, y, w in edges:
            if uf.merge(x, y, w):
                ans += 1
        return ans