/*
https://codeforces.com/problemset/problem/2227/D

输入 T(≤1e4) 表示 T 组数据。所有数据的 2n 之和 ≤2e5。
每组数据输入 n(1≤n≤1e5) 和长为 2n 的数组 a，保证 [0,n-1] 中的每个整数都恰好出现两次。

设 b 是 a 中的一个回文的连续子数组。
求 mex(b) 的最大值。

注：mex(b) 是不在 b 中的最小非负整数。


思路：
暴力判断可以以通过，
更快的解法
因为子数组 [0] 满足要求，所以答案至少是 1。
为了让答案变得更大，子数组至少要包含 0。
由于子数组是回文的，0 要么是回文中心，要么关于回文中心对称（此时可以算出回文中心）。
所以回文中心只有三种情况，分别计算对应的最长回文子数组（元素越多 mex 越大），统计哪些元素出现过，然后求 mex。
代码写法：
记录两个0的位置p1, p2
如果p1 + 1 == p2, 那么p1, p2一定是回文中心
否则，对p1, p2, (p1 + p2) 分别作为回文中心，取三者最大值
*/

#include <bits/stdc++.h>

void solve1() {
    int n;
    std::cin >> n;
    std::vector<int> a(2 * n);
    std::vector<int> p;
    for (int i = 0; i < n * 2; i++) {
        std::cin >> a[i];
        if (a[i] == 0) {
            p.push_back(i);
        }
    }
    int ans = 1;
    auto check = [&](int l, int r) -> int {
        if (a[l + 1] != a[r - 1]) {
            return 0;
        }
        std::vector<int> cnt(n);
        cnt[a[l + 1]] = 1;
        while (l >= 0 && r < 2 * n && a[l] == a[r]) {
            cnt[a[l]] = 1;
            l--, r++;
        }
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0) {
                return i;
            }
        }
        return n;
    };
    if (p[0] + 1 == p[1]) {
        ans = check(p[0] - 1, p[1] + 1);
    } else {
        ans = std::max(check(p[0] - 1, p[0] + 1), check(p[1] - 1, p[1] + 1));
        int m = (p[0] + p[1]) / 2;
        ans = std::max(ans, check(m - 1, m + 1 + ((p[0] + p[1]) & 1)));
    }
    std::cout << ans << '\n';
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(2 * n);
    for (int i = 0; i < n * 2; i++) {
        std::cin >> a[i];
    }
    int ans = 1;
    std::vector<int> cnt(n + 1);
    int idx = 1;
    auto check = [&](int l, int r) -> int {
        cnt[a[l + 1]] = idx;
        while (l >= 0 && r < 2 * n && a[l] == a[r]) {
            cnt[a[l]] = idx;
            l--, r++;
        }
        for (int i = 0; i < n; i++) {
            if (cnt[i] != idx) {
                return i;
            }
        }
        return n;
    };
    for (int i = 1; i < 2 * n - 1; i++) {
        int l = i - 1, r = i + 1;
        if (a[i + 1] == a[i]) {
            r++;
        }
        ans = std::max(ans, check(l, r));
        idx++;
    }
    std::cout << ans << '\n';
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        // solve();
        solve1();
    }
    return 0;
}
