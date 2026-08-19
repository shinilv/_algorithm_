/*
题意：
https://codeforces.com/problemset/problem/2252/B

输入 T(≤1e4) 表示 T 组数据。所有数据的 n 之和 ≤2e5。
每组数据输入 n(1≤n≤2e5) 和长为 n 的 01 字符串 s。

每次操作，你可以删除 s 中的一个字符。要求操作序列必须是交替的，例如这次操作删除 0，那么下次操作只能删除 1。第一次操作可以删除 0 或 1。

输出把 s 变成交替字符串（0101... 或者 1010...）的最小操作次数。
如果无法把 s 变成交替字符串，输出 -1。
思路：
模拟 0开头 或 1 开头，然后判断是否可以形成交替字符串。
*/


#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    auto check = [&](char c) {
        int cnt[2]{};
        int cur = c - '0';
        for (int i = 0; i < n; i++) {
            if (s[i] - '0' != cur) {
                cnt[s[i] - '0']++;
            } else {
                cur ^= 1;
            }
        }
        if (abs(cnt[0] - cnt[1]) <= 1) {
            return cnt[0] + cnt[1];
        }
        if (cur != c - '0') {
            cnt[c - '0'] += 1;
            if (abs(cnt[0] - cnt[1]) <= 1) {
                return cnt[0] + cnt[1];
            }
        } else {
            cnt[cur ^ 1] += 1;
            if (abs(cnt[0] - cnt[1]) <= 1) {
                return cnt[0] + cnt[1];
            }
        }
        return n + 1;
    };
    int ans1 = check('1'), ans2 = check('0');
    int ans = std::min(ans1, ans2);
    if (ans > n) {
        std::cout << -1 << "\n";
    } else {
        std::cout << ans << "\n";
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
