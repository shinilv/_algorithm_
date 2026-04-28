/*
题意： 以网格的形式给定一些数，每次
选择一个数 加或减 x， 计算最少多少次可以使得所有数相等
如果不能能使得所有数相等，返回 -1
思路：找到最大值，和其他的数做差为t
ans = sum(t / x) 如果存在t % x != 0，返回 -1

中位数贪心，找到数组中的中位数，把所有的数变为这个中位数是最优的
*/


class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        int mx = 0;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mx = max(mx, grid[i][j]);
                a.push_back(grid[i][j]);
            }
        }
        sort(a.begin(), a.end());
        int ans = 0, t = a[(n * m) / 2];
        for (auto i : a) {
            int v = mx - i;
            if (v % x != 0) return -1;
            ans += abs(i - t) / x;
        }
        return ans;
    }
};