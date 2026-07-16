"""
https://atcoder.jp/contests/abc439/tasks/abc439_f

输入 n(1≤n≤3e5) 和 1~n 的排列 p。

输出 p 有多少个子序列 b，满足 b 的峰的个数 > b 的谷的个数。
答案模 998244353。

注：对于一个长为 m 的序列 a（下标从 1 到 m），定义「峰」和「谷」如下：
如果 a[i] 满足 2 ≤ i ≤ m-1 且 a[i-1] < a[i] > a[i+1]，称 a[i] 为峰。
如果 a[i] 满足 2 ≤ i ≤ m-1 且 a[i-1] > a[i] < a[i+1]，称 a[i] 为谷。

输入
4
1 3 4 2
输出 4
解释：合法子序列为 (1,3,4,2), (1,3,2), (1,4,2), (3,4,2)。

输入
1
1
输出 0

输入
20
11 10 18 13 12 16 5 19 7 6 17 4 9 1 14 2 20 15 8 3
输出 431610


思路：

基本性质：
1. 由于 p 中没有重复元素，所以峰谷一定是交替出现的。
2. 合法子序列一开始是递增的，最后是递减的，这样峰的个数才能大于谷的个数。

本题是相邻相关子序列 DP，考虑「枚举选哪个」。
由于有递增递减两个状态，考虑状态机 DP。

定义 inc[i] 表示以 a[i] 结尾且最后两个数是递增的子序列的个数。
定义 dec[i] 表示以 a[i] 结尾且最后两个数是递减的子序列的个数。

枚举子序列倒数第二个数是 a[j]。
a[j] 与子序列倒数第三个数可以是递增关系（从 inc[j] 转移过来），也可以是递减关系（从 dec[j] 转移过来）。
如果 a[j] < a[i]，那么 inc[i] += inc[j] + dec[j]。这可以用值域树状数组优化。
然后把 inc[i] 加一，表示 1 个数单独形成一个子序列。
如果 a[j] > a[i]，那么 dec[i] += inc[j] + dec[j]。这可以用值域树状数组优化。
由于 inc[j] 包含 1 个数的情况，要把 dec[i] 减去遍历过的大于 a[i] 的数的个数。
注：题目要求峰的个数大于谷的个数，第一个峰/谷必须是峰，我们不能从 1 个数的状态转移到 dec，那样一开始是谷。

合法子序列最后是递减的，所以答案为 sum(dec)，即树状数组的 dec.query(1,n)。


代码
"""

MOD = 998244353

class BTree:
    def __init__(self, n: int):
        self.n = n
        self.a = [0] * (n + 1)

    def add(self, idx:int, val:int):
        while idx <= self.n:
            self.a[idx] = (self.a[idx] + val + MOD) % MOD
            idx += (idx & -idx)

    def sum(self, idx:int):
        res = 0
        while idx > 0:
            res = (res + self.a[idx] + MOD) % MOD
            idx -= (idx & -idx)
        return res


n = int(input())

a = list(map(int, input().split()))

inc = BTree(n)
dec = BTree(n)
bt = BTree(n)

for i, x in enumerate(a):
    v1 = (inc.sum(x - 1) + dec.sum(x - 1)) % MOD
    v2 = ((inc.sum(n) - inc.sum(x - 1) + MOD) % MOD +
                (dec.sum(n) - dec.sum(x - 1) + MOD) % MOD) % MOD
    inc.add(x, v1)
    inc.add(x, 1)
    dec.add(x, v2)
    dec.add(x, bt.sum(x) - bt.sum(n))
    bt.add(x, 1)
print(dec.sum(n))
