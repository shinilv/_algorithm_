/*
题意：
给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

思路：
暴力枚举每一个分割方式
*/


class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<string> path;
        vector<vector<string>> ans;

        auto check = [&](string t) -> bool {
            string temp = t;
            reverse(t.begin(), t.end());
            return temp == t;
        };

        auto dfs = [&](auto&& dfs, int u, string cur) -> void {
            if (u == n) {
                if (!check(cur)) return;
                path.push_back(cur);
                ans.push_back(path);
                path.pop_back();
                return;
            }
            if (cur.empty()) {
                cur += s[u];
                dfs(dfs, u + 1, cur);
            } else {
                if (check(cur)) {
                    path.push_back(cur);
                    dfs(dfs, u, "");
                    path.pop_back();
                }
                cur += s[u];
                dfs(dfs, u + 1, cur);
            }
        };
        dfs(dfs, 0, "");
        return ans;
    }
};
