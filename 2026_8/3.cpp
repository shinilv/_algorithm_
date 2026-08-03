/*
题意：
https://codeforces.com/problemset/problem/2241/D
输入 T(≤1e4) 表示 T 组数据。所有数据的 n 之和 ≤2e5。
每组数据输入 n(1≤n≤2e5) 长为 n 的数组 a(1≤a[i]≤1e9) 和长为 n 的数组 b(1≤b[i]≤1e9)。
你可以执行如下操作任意次：
选择 a 的一个非空连续子数组 [L,R]，对于 L≤i≤R，如果 i-L 是偶数，则把 a[i] 增加 1，否则把 a[i] 减少 1。
能否把 a 变成 b？输出 YES 或 NO。

思路：
记 cnt = 0
从后往前遍历，如果a[i] < b[i], v = b[i] - a[i], 如果cnt > 0 先抵消cnt, cnt = max(0, cnt - v)
            否则 cnt = cnt + v
最后判断 cnt 是否为0即可

输入
7
3
1 2 3
1 2 3
4
1 4 5 2
1 5 4 3
1
9
8
6
6 7 6 7 6 7
7 6 7 6 7 6
9
9 8 7 6 5 4 3 2 1
9 9 8 2 4 4 3 5 3
3
1 1 2
2 1 1
2
1 2
1 1
输出
YES
YES
NO
YES
NO
YES
NO
*/
#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];
    int cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        int v = abs(b[i] - a[i]);
        if (a[i] < b[i]) {
            cnt = std::max(0, cnt - v);
        } else {
            cnt += v;
        }
    }
    std::cout << (cnt == 0 ? "YES" : "NO") << "\n";
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

