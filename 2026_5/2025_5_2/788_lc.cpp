/*
题意：统计满足1 - n 之间满足 旋转 180 度后仍然是合法数字，并且和原数字不同的数的个数。
思路：暴力枚举，首先符合要求的数不能包含 3, 4, 7 这三个数字
*/

class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i);
            int f1 = 1, f2 = 0;
            for (auto x : s) {
                if (x == '3' || x == '4' || x == '7') {
                    f1 = 0;
                    break;
                } else if (x == '2' || x == '5' || x == '6' || x == '9') {
                    f2 = 1;
                }
            }
            if (f1 && f2) ans++;
        } 
        return ans;
    }
};