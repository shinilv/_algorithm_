/*
题意：
给你一个字符串 s，找到 s 中最长的 回文 子串。
思路：
中心扩展发，暴力枚举每一个或两个位置作为回文串的中心，具体写法参考代码

*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 0;
        auto check = [&](int& l, int& r) -> void {
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--, r++;
            }
        };
        string ret;
        for (int i = 0; i < 2 * n; i++) {
            int l = i / 2, r = (i + 1) / 2;
            check(l, r);
            if (ans < (r - l - 1)) {
                ans = r - l - 1;
                ret = s.substr(l + 1, r - l - 1);
            }
        }
        return ret;
    }
};
