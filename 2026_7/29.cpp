/*
https://codeforces.com/problemset/problem/2238/C

输入 T(≤1e4) 表示 T 组数据。所有数据的 n 之和 ≤2e5。
每组数据输入 n(2≤n≤2e5)，表示一棵 n 个节点的有根树，根为 1。节点编号从 1 到 n。
然后输入长为 n-1 的数组 p(1≤p[i]≤i-1)，下标从 2 到 n，表示节点 i 的父节点为 p[i]。

在子树 v 中，到 v 距离为一个非负整数 h 的所有点，组成了一个公会（guide）。
例如 h=0 表示节点 v，h=1 表示节点 v 的所有儿子，h=2 表示节点 v 的所有儿子的儿子。

输出整棵树有多少个不同的公会。
如果存在一个点属于公会 A 但不属于公会 B，那么 A 和 B 是不同的公会。

思路：

/*
                 1 (增量就是4， 节点2和4的高度都是4)
		 2         3      4
	5    6   7              11
  8  9                        12
     10                         23
从下往上算，考虑增量（新增的公会数）。

如果节点 v 只有一个儿子，那么只能节点 v 自己组成一个公会，增量为 1。
否则，设节点 v 的儿子的次大高度为 h2，那么 v 这一层，以及从 v 往下数 h2 层，都是新的公会。增量为 1 + h2。

代码实现时，可以初始化 ans = n，上面的增量 1 + h2 可以写成 h2。

*/



#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++) {
        int x;
        std::cin >> x;
        g[x].push_back(i);
    }
    int ans = n;

    auto dfs = [&](auto&& dfs, int u) -> int {
        int mx1 = 0, mx2 = 0; // 记录最大高和次大高
        for (int v : g[u]) {
            int h = dfs(dfs, v);
            if (mx1 == 0) {
                mx1 = h;
            } else if (mx2 == 0) {
                if (h > mx1) {
                    mx2 = mx1;
                    mx1 = h;
                } else {
                    mx2 = h;
                }
            } else {
                if (h > mx1) {
                    mx2 = mx1;
                    mx1 = h;
                } else if (h > mx2) {
                    mx2 = h;
                }
            }
        }
        ans += mx2;
        return mx1 + 1;
    };
    dfs(dfs, 1);

    std::cout << ans << '\n';

}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
