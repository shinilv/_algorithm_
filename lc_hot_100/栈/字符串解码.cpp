/*
题意：
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

测试用例保证输出的长度不会超过 105。

思路：
使用两个栈来维护
*/

class Solution
{
   public:
    string decodeString(string s)
    {
        stack<int> st1;
        stack<string> st2;
        string cur;
        int cnt = 0;
        for (char ch : s) {
            if (ch >= '0' && ch <= '9') {
                cnt = cnt * 10 + (ch - '0');
            } else if (ch == '[') {
                st1.push(cnt);
                st2.push(cur);
                cur.clear();
                cnt = 0;
            } else if (ch == ']') {
                int t = st1.top();
                st1.pop();
                string prev = st2.top();
                st2.pop();
                while (t--) {
                    prev += cur;
                }
                cur = prev;
            } else {
                cur += ch;
            }
        }
        return cur;
    }
};
