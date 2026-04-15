class SegmentTree:
    def __init__(self, arr, target_gcd:int):
        n = len(arr)
        self._target_gcd = target_gcd
        self._n = n
        self._tree = [0] * 4 * n
        self._build(arr, 1, 0, n - 1)
    
    def _maintain(self, node: int) -> None:
        self._tree[node] = gcd(self._tree[node * 2], self._tree[node * 2 + 1])

    def _build(self, a: List[int], node: int, l: int, r: int) -> None:
        if l == r:
            self._tree[node] = a[l] if a[l] % self._target_gcd == 0 else 0
            return
        m = l + r >> 1
        self._build(a, node * 2, l, m)
        self._build(a, node * 2 + 1, m + 1, r)
        self._maintain(node)
    def _update(self, node: int, l: int, r: int, i: int, val: int) -> None:
        if l == r:
            self._tree[node] = val if val % self._target_gcd == 0 else 0
            return
        m = l + r >> 1
        if i <= m:
            self._update(node * 2, l, m, i, val)
        else:
            self._update(node * 2 + 1, m + 1, r, i, val)
        self._maintain(node)
    def _query(self, node: int, l: int, r: int, ql: int, qr: int) -> int:
        if ql > qr:
            return 0
        if ql <= l and r <= qr:
            return self._tree[node]
        m = l + r >> 1
        if qr <= m:
            return self._query(node * 2, l, m, ql, qr)
        if ql > m:
            return self._query(node * 2 + 1, m + 1, r, ql, qr)
        l_res = self._query(node * 2, l, m, ql, qr)
        r_res = self._query(node * 2 + 1, m + 1, r, ql, qr)
        return gcd(l_res, r_res)
    def update(self, i: int, val: int) -> None:
        self._update(1, 0, self._n - 1, i, val)
    def query(self, ql: int, qr: int) -> int:
        return self._query(1, 0, self._n - 1, ql, qr)
    def query_all(self) -> int:
        return self._tree[1]
    def check(self, n: int) -> bool:
        return any(gcd(self.query(0, i - 1), self.query(i + 1, n - 1)) == self._target_gcd for i in range(n))

class Solution:
    def countGoodSubseq(self, nums: list[int], p: int, queries: list[list[int]]) -> int:
        n = len(nums)
        seg = SegmentTree(nums, p)
        ans = 0
        cnt_p = sum(x % p  == 0 for x in nums)
        for i, x in queries:
            if nums[i] % p == 0:
                cnt_p -= 1
            if x % p == 0:
                cnt_p += 1
            nums[i] = x
            seg.update(i, x)
            if seg.query_all() == p and (cnt_p < n or n > 6 or seg.check(n)):
                ans += 1
        return ans