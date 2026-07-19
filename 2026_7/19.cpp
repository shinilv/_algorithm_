/*
题意：
返回 s 字典序最小的子序列，该子序列包含 s 的所有不同字符，且只包含一次。
思路：

*/


class Solution {
public:
    string smallestSubsequence(string s) {
        int cnt[26]{}, vis[26]{};
        for (auto x : s) {
            cnt[x - 'a'] += 1;
        }
        string ans;
        for (char ch : s) {
            if (vis[ch - 'a'] == 0) {
                while (ans.size() && ch < ans.back()) {
                    if (cnt[ans.back() - 'a'] > 0) {
                        vis[ans.back() - 'a'] = 0;
                        ans.pop_back();
                    } else {
                        break;
                    }
                }
                ans += ch;
                vis[ch - 'a'] = 1;
            }
            cnt[ch - 'a'] -= 1;
        }
        return ans;
    }
};
