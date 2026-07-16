"""
https://atcoder.jp/contests/arc223/tasks/arc223_b

输入 T(≤1e5) 表示 T 组数据。所有数据的 n 之和 ≤2e5。
每组数据输入 n(2≤n≤2e5) k(1≤k≤1e9) 和长为 n 的数组 a(1≤a[i]≤1e9)。

你可以执行如下操作任意次：
对于 a 中的相邻元素 a[i] 和 a[i+1]，
如果 a[i]+a[i+1] 是 k 的倍数，那么可以交换 a[i] 和 a[i+1]。

输出可以得到多少个不同的数组，模 998244353。
注：数组 A ≠ B，当且仅当存在下标 i 使得 A[i] ≠ B[i]。

思路：
两个相邻元素 x 和 y，如果 (x+y)%k = 0，那么可以交换。交换后，x 与 z 相邻，如果 x+z 也是 k 的倍数，那么可以继续交换 x 和 z。
这意味着，连续的与 x 或者 k-x 模 k 同余的数，在同一组中，我们要计算这一组有多少个不同的序列。

分类讨论：
- 如果 x%k ≠ (k-x%k)%k，那么与 x 模 k 同余的数，顺序不能变（无法交换）；
与 k-x 模 k 同余的数，顺序不能变（无法交换）。设这一组有 m 个数，其中与 x 模 k 同余的数有 p 个，那么有 C(m,p) 种方案。
- 如果 x%k = (k-x%k)%k，那么这一组可以随便换，用可重集排列数公式计算。

组与组之间互相独立，根据乘法原理相乘，即为答案。

遍历每一组可以用分组循环。


"""
from collections import Counter
MOD = 998244353

N = 200000

fac = [1] * (N + 1)
inv_fac = [1] * (N + 1)

for i in range(1, N + 1):
    fac[i] = fac[i - 1] * i % MOD

inv_fac[N] = pow(fac[N], MOD - 2, MOD)

for i in range(N, 0, -1):
    inv_fac[i - 1] = inv_fac[i] * i % MOD


def C(n: int, k: int) -> int:
    if k < 0 or k > n:
        return 0

    return fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD

def func(nums: list) -> int:
    ans = fac[len(nums)]

    for count in Counter(nums).values():
        ans = (ans * inv_fac[count]) % MOD

    return ans

for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    i, ans, cnt1, t = 0, 1, 0, -1

    cur = []
    while i < n:
        cur.append(a[i])
        if t != -1 and a[i] % k == t:
            cnt1 += 1
        if i == n - 1:
            if t != -1:
                ans = ans * C(len(cur), cnt1) % MOD
            else:
                ans = ans * func(cur) % MOD
            break
        if (a[i] + a[i + 1]) % k == 0 or a[i] % k == a[i + 1] % k:
            if t == -1 and a[i] % k != (k - a[i] % k) % k:
                t = (k - a[i] % k) % k
        else:
            if t != -1:
                ans = ans * C(len(cur), cnt1) % MOD
            else:
                ans = ans * func(cur) % MOD
            cur.clear()
            t = -1
            cnt1 = 0
        i += 1
    print(ans)

