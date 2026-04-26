/*
题意：给你一个 m x n 的字符网格，判断是否存在一个由相同字符组成的环；
环要求路径长度至少为 4，每次只能上下左右移动，且不能直接走回上一步所在格子。
数据范围：m == grid.length，n == grid[i].length，1 <= m, n <= 500，grid 只包含小写英文字母。

思路：
bfs搜索，搜过的格子做一个标记
dfs的时候，把前一个点也加上，判断下一个点必须和前一个不同
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        auto dfs = [&](auto&& dfs, int x, int y, int px, int py) -> bool {
            vis[x][y] = true;
            for (int d = 0; d < 4; d++) {
                int tx = dx[d] + x, ty = dy[d] + y;
                if (tx >= 0 && tx < n && ty >= 0 && ty < m && 
                    (px != tx || py != ty) &&
                    grid[tx][ty] == grid[x][y] && 
                    (vis[tx][ty] || dfs(dfs, tx, ty, x, y))) {
                        return true;
                }
            }
            return false;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && dfs(dfs, i, j, -1, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};