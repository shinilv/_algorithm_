"""
https://atcoder.jp/contests/adt_all_20260504_2/tasks/abc432_e

输入 n(1≤n≤5e5) q(1≤q≤2e5) 和长为 n 的数组 a(0≤a[i]≤5e5)。下标从 1 开始。
然后输入 q 个询问，格式如下：
"1 i v"：把 a[i] 改成 v(0≤v≤5e5)。
"2 L R"：定义 b[i] = max(L, min(R, a[i]))，输出 sum(b)。(0≤L,R≤5e5)

思路：
 <= L 的数都变成 L，
>= R 的数都变成 R。
用值域树状数组维护 <= v 的元素个数，以及元素和。

对于 L >= R 的情况，输出 n*L。
"""

n, q = map(int, input().split())

M = 500006  # 值域上限
cnt = [0] * M  # 值域计数 BIT
sm = [0] * M   # 值域求和 BIT


def add(i, x, f=1):
    """值域位置 i 加上 x（i>=1）"""
    while i < M:
        cnt[i] += f
        sm[i] += x
        i += i & (-i)


def qry(i):
    """返回 [1..i] 的前缀和"""
    c = s = 0
    while i > 0:
        c += cnt[i]
        s += sm[i]
        i -= i & (-i)
    return c, s


a = list(map(int, input().split()))
for i in range(n):
    add(a[i] + 1, a[i])

for _ in range(q):
    p = list(map(int, input().split()))
    if p[0] == 1:
        i, v = p[1], p[2]
        i -= 1
        add(a[i] + 1, -a[i], -1)
        add(v + 1, v)
        a[i] = v
    else:
        L, R = p[1], p[2]
        if L >= R:
            print(n * L)
            continue
        lo, hi = L, R + 1
        lc, ls = qry(lo)
        rc, rs = qry(hi)
        # print(rs, ls, lc, rc)
        # qry(lo)=值<L 的计数和和, qry(hi)=值<=R 的计数和和
        # [L,R] 区间不变: rs - ls
        # <L 变 L: L * lc
        # >R 变 R: R * (n - rc)
        print(rs - ls + L * lc + R * (n - rc))
