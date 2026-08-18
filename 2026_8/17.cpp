/*

题意：
https://codeforces.com/problemset/problem/2254/E

输入 T(≤1e4) 表示 T 组数据。所有数据的 n 之和 ≤2e5。
每组数据输入 n(1≤n≤2e5) 和长为 n 的数组 d(-1e9≤d[i]≤1e9)。

设 diff 是某个正整数数组 a 的差分数组。即 diff[1] = a[1]，i>1 时 diff[i] = a[i] - a[i-1]。
d 是 diff 重排后的数组。

请你还原数组 a。必须满足 a[i] >= 1。
如果不存在 a，输出 -1。否则输出字典序最小的 a。

思路：
根据 >= 0 和 < 0， 把diff数组分成两个数组 x, y;
对x数组进行排序，
对于构建数组a
如果sum(x) < abs(sum(y)), 则不存在数组a，输出-1
否则令a[1] = 数组x中 > 0 的最小值，记录这个位置为p
然后每次查找数组b中元素 t 绝对值 < a[cur] 的元素，最为a[cur+1] = a[cur] - t。如果没有就a[cur + 1] = a[cur] + x[j++]
*/

#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> d(n), x;
    std::multiset<int, std::greater<int>> mse;
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
        if (d[i] >= 0) {
            x.push_back(d[i]);
        } else {
            mse.insert(-d[i]);
        }
    }
    std::sort(x.begin(), x.end());
    std::vector<long long> a;
    int p = -1;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] > 0) {
            a.push_back(x[i]);
            p = i;
            break;
        }
    }
    if (p == -1) {
        std::cout << -1 << std::endl;
        return;
    }
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (j == p) j++;
        auto it = mse.upper_bound(a.back());
        if (it != mse.end() && *it < a.back()) {
            a.push_back(a.back() - *it);
            mse.erase(it);
        } else {
            if (j < x.size()) {
                a.push_back(a.back() + x[j++]);
            } else {
                std::cout << -1 << std::endl;
                return;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
