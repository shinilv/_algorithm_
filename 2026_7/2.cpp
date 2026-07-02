/*
题意：
给你一个 m x n 的二进制矩形 grid 和一个整数 health 表示你的健康值。
你开始于矩形的左上角 (0, 0) ，你的目标是矩形的右下角 (m - 1, n - 1) 。
你可以在矩形中往上下左右相邻格子移动，但前提是你的健康值始终是 正数 。
对于格子 (i, j) ，如果 grid[i][j] = 1 ，那么这个格子视为 不安全 的，会使你的健康值减少 1 。
如果你可以到达最终的格子，请你返回 true ，否则返回 false 。
注意 ，当你在最终格子的时候，你的健康值也必须为 正数 。

0 < n, m <= 50
思路：
bfd搜索即可
*/



class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m,  vector<int>(n, -1));
        health -= grid[0][0];
        vis[0][0] = health;
        vector<array<int, 2>> qu;
        qu.push_back({0, 0});
        while (qu.size()) {
            vector<array<int, 2>> temp;
            for (auto [x, y] : qu) {
                for (int i = 0; i < 4; i++) {
                    int tx = dx[i] + x, ty = dy[i] + y;
                    if (tx >= 0 && tx < m && ty >= 0 && ty < n) {
                        int v = vis[x][y] - grid[tx][ty];
                        if (v > 0 && v > vis[tx][ty]) {
                            if (tx == m - 1 && ty == n - 1) {
                                return true;
                            }
                            vis[tx][ty] = v;
                            temp.push_back({tx, ty});
                        }
                    }
                }
            }
            qu.swap(temp);
        }
        return false;
    }
};
