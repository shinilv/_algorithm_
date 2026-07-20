/*
题意：
https://atcoder.jp/contests/abc384/tasks/abc384_d

输入 n(1≤n≤2e5) S(1≤S≤1e18) 和长为 n 的数组 a(1≤a[i]≤1e9)。

定义无穷序列 b = a + a + a + ...
在 b 中是否存在和为 S 的非空连续子数组？
输出 Yes 或 No。


思路：

*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n * 2);
    int sum = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        a[i + n] = a[i];
    }
    s %= sum;
    mp[0] = 1;
    string ans = "No\n";
    if (s == 0) {
        cout << "Yes\n";
        return 0;
    }
    for (int i = 0; i < 2 * n; i++) {
        sum += a[i];
        if (mp.count(sum - s)) {
            ans = "Yes\n";
            break;
        }
        mp[sum] = 1;
    }
    cout << ans;
    return 0;
}
