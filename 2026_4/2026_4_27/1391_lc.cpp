
/*

*/

class Solution {
    static constexpr int dis[7][2][2] = {
        {},
        {{0, 1}, {0, -1}},
        {{1, 0}, {-1, 0}},
        {{0, -1}, {1, 0}},
        {{0, 1}, {1, 0}},
        {{-1, 0}, {0, -1}},
        {{-1, 0}, {0, 1}},
    };
    bool contains(int s, int dx, int dy) {
        auto& ds = dis[s];
        return ds[0][0] == dx && ds[0][1] == dy ||
                ds[1][0] == dx && ds[1][1] == dy;
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        auto dfs = [&](auto&& dfs, int x, int y) -> bool {
            if (x == n - 1 && y == m - 1) return true;
            vis[x][y] = true;
            for (auto& [dx, dy] : dis[grid[x][y]]) {
                int i = x + dx, j = y + dy;
                if (i >= 0 && i < n && j >= 0 && j < m &&
                !vis[i][j] && contains(grid[i][j], -dx, -dy) && dfs(dfs, i, j)) {
                    return true;
                }
            }
            return false;
        };
        return dfs(dfs, 0, 0);
    }
};