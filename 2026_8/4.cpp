/*
题意：
给定一个

1 2 3 4 5 6 -8 3 -10
1 1 1 1 1 1 1 1 1 1

思路：
f[i] = sum(i, n - 1) - f[i + 1]
f[i] = sum(i, n - 1) - f[i + 2]
f[i] = sum(i, n - 1) - f[i + 3]
f[i] 表示表示还剩下第 i,i+1,⋯,n−1 堆石子时，当前玩家最多能从剩下的石子中拿到的石子数目
*/


class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> f(n + 1), pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + stoneValue[i];
        }
        f[n - 1] = stoneValue[n - 1];
        if (n > 1)
            f[n - 2] = stoneValue[n - 2] + max(0, stoneValue[n - 1]);

        for (int i = n - 3; i >= 0; i--) {
            f[i] = pre[n] - pre[i] - min({f[i + 1], f[i + 2], f[i + 3]});
        }
        if (f[0] > double(pre[n]) / 2) {
            return "Alice";
        } else if (f[0] < double(pre[n]) / 2) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};
