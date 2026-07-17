/*
题意：

https://atcoder.jp/contests/abc397/tasks/abc397_f

输入 n(3≤n≤3e5) 和长为 n 的数组 a(1≤a[i]≤n)。

把 a 切两刀，分成三个非空连续子数组 A,B,C。

分别计算这三个子数组的不同元素个数，得到 x,y,z。
输出 x+y+z 的最大值。

样例：
输入
5
3 1 4 1 5
输出 5
解释：一种分割方案是 [3,1] + [4,1] + [5]。
输入
10
2 5 6 4 4 1 1 3 1 4
输出 9

思路：
关键性质：

设 a[i] 上一次出现的位置为 last[a[i]]。把 a[i] 添加到左端点在 [last[a[i]]+1, i-1] 中，
右端点为 i-1 的子数组的末尾，可以让这个子数组的不同元素个数增加 1。
如果这个子数组的左端点 <= last[a[i]]，那么添加 a[i] 不改变该子数组的不同元素个数。

定义 f[i][k][j] 表示考虑 a 的前 i 个数，且第 k 个子数组的左端点为 j 时，前 k 个子数组的不同元素个数之和。
分类讨论：
- a[i] 单独形成一个子数组。问题变成考虑 a 的前 i-1 个数，
且第 k-1 个子数组的左端点为 j 时，前 k-1 个子数组的不同元素个数之和，
即 f[i-1][k-1][j]，枚举 j=1,2,...,i-1，取最大值，再加 1，得到 f[i][k][i]。
- a[i] 拼在子数组的末尾。根据关键性质，
f[i-1][k] 的区间 [last[a[i]]+1, i-1] 增加 1，即为 f[i][k] 的区间 [last[a[i]]+1, i-1]。
这可以用三棵 Lazy 线段树维护。去掉 f 的第一个维度。

初始值：全为 0。
答案：k=3 对应线段树的最大值。

代码

*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegTreeLazyRangeMaxAdd {
   private:
    vector<T> tree, lazy;
    vector<T>* arr;
    int n;
    int root;
    int end;
    // 下推懒惰标记
    void push_down(int cl, int cr, int p) {
        if (cl != cr && lazy[p] != T{}) {
            tree[p * 2] += lazy[p];
            tree[p * 2 + 1] += lazy[p];
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
            lazy[p] = T{};
        }
    }
    // 上推更新父节点：维护区间最大值
    void push_up(int p) {
        tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
    }
    // 查询区间最大值
    T range_max(int l, int r, int cl, int cr, int p) {
        if (l <= cl && cr <= r) {
            return tree[p];
        }
        push_down(cl, cr, p);
        int m = cl + (cr - cl) / 2;
        T max_val = numeric_limits<T>::lowest();
        if (l <= m) {
            max_val = max(max_val, range_max(l, r, cl, m, p * 2));
        }
        if (r > m) {
            max_val = max(max_val, range_max(l, r, m + 1, cr, p * 2 + 1));
        }
        return max_val;
    }
    // 区间加法更新
    void range_add(int l, int r, T val, int cl, int cr, int p) {
        if (l <= cl && cr <= r) {
            tree[p] += val;
            lazy[p] += val;
            return;
        }
        push_down(cl, cr, p);
        int m = cl + (cr - cl) / 2;
        if (l <= m) {
            range_add(l, r, val, cl, m, p * 2);
        }
        if (r > m) {
            range_add(l, r, val, m + 1, cr, p * 2 + 1);
        }
        push_up(p);
    }

    // 构建线段树
    void build(int s, int t, int p) {
        if (s == t) {
            tree[p] = (*arr)[s];
            return;
        }
        int m = s + (t - s) / 2;
        build(s, m, p * 2);
        build(m + 1, t, p * 2 + 1);
        push_up(p);
    }

   public:
    explicit SegTreeLazyRangeMaxAdd(const vector<T>& v) {
        n = static_cast<int>(v.size());
        root = 1;
        end = n - 1;
        tree.resize(n * 4, numeric_limits<T>::lowest());
        lazy.resize(n * 4, T{});
        arr = const_cast<vector<T>*>(&v);
        build(0, end, root);
        arr = nullptr;
    }
    // 查询区间 [l, r] 的最大值，使用 1-based 下标
    T query_max(int l, int r) {
        if (l > r) return 0;
        return range_max(l - 1, r - 1, 0, end, root);
    }
    // 区间 [l, r] 中所有元素加 val，使用 1-based 下标
    void add(int l, int r, T val) {
        if (l > r) return;
        range_add(l - 1, r - 1, val, 0, end, root);
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    // f[i][k][j] 表示当前a[i] 属于第k个子数组，然后第k个子数组的左端点是j 的最大值
    // 如果当前a[i] 作为一个新的数组 f[i][k][i] = max(f[i - 1][k - 1][j]) + 1, j = 0, 1, 2, ... , i - 1
    // 否则，f[i][k][j] = max(f[i - 1][k][j]) + 1, j = last[a[i]] + 1, last[a[i]] + 2, ..., i - 1
    vector<int> temp(n, 0);

    vector<SegTreeLazyRangeMaxAdd<int>> dp(3, SegTreeLazyRangeMaxAdd<int>(temp));
    vector<int> last(n + 1);

    for (int i = 0; i < n; i++) {
        int cnt[3]{};
        for (int j = 0; j < 3; j++) cnt[j] = dp[j].query_max(1, i);
        for (int k = 0; k < 3; k++) {
            if (k)
                dp[k].add(i + 1, i + 1, cnt[k - 1] + 1);
            else if (i == 0)
                dp[k].add(i + 1, i + 1, 1);
            dp[k].add(last[a[i]] + 1, i, 1);
        }
        last[a[i]] = i + 1;
    }

    std::cout << dp[2].query_max(1, n);

    return 0;
}
