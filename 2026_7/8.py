
"""
https://atcoder.jp/contests/adt_all_20260504_2/tasks/abc432_e

输入 n(1≤n≤5e5) q(1≤q≤2e5) 和长为 n 的数组 a(0≤a[i]≤5e5)。下标从 1 开始。
然后输入 q 个询问，格式如下：
"1 i v"：把 a[i] 改成 v(0≤v≤5e5)。
"2 L R"：定义 b[i] = max(L, min(R, a[i]))，输出 sum(b)。(0≤L,R≤5e5)

思路：

"""
