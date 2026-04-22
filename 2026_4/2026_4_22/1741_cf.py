"""
题意：
https://codeforces.com/problemset/problem/1741/E

输入 T(≤1e4) 表示 T 组数据。所有数据的 n 之和 ≤2e5。
每组数据输入 n(1≤n≤2e5) 和长为 n 的数组 b(1≤b[i]≤1e9)。

对于一个数组 a，可以按照如下规则生成另一个数组 a'：
1. 把 a 划分成若干非空段（也可以不划分）。
2. 在每一段的左侧或者右侧，插入一个整数 L，其中 L 是这一段的长度。
3. 得到数组 a'。

例如 a = [1,2,3,1,2,3]：
1. 划分成 [1] + [2,3,1] + [2,3]。
2. 在第一段的左侧插入 1，第二段的右侧插入 3，第三段的左侧插入 2。
3. 得到 a' = [1,1,2,3,1,3,2,2,3]。

是否存在数组 a，可以生成数组 b？输出 YES 或 NO。

思路：
f[i] 表示当前是插入的长度
这样有两种转移方法
此时是插入的左边，那么 f[i] |= f[i - a[i - 1] - 1]
右边： f[i + a[i - 1]] |= f[i - 1]
初始f[0] = True
结果就是f[n]
"""
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    f = [False] * (n + 1)
    f[0] = True
    for i in range(1, n + 1):
        b = a[i - 1]
        if i + b <= n:
            f[i + b] |= f[i - 1]
        if i - b - 1 >= 0:
            f[i] |= f[i - b - 1]
    if f[n]:
        print("YES")
    else:
        print("NO")