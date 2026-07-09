/*
题意：
给定一个整数数组 temperatures ，表示每天的温度，
返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，
下一个更高温度出现在几天后。
如果气温在这之后都不会升高，请在该位置用 0 来代替。

思路：
从后往前遍历温度数组，使用一个栈来存储温度的索引。
对于每个温度，弹出栈中所有小于等于当前温度的索引，直到栈为空或栈顶温度大于当前温度。
如果栈为空则说明当前温度之后没有更高的温度，设置 answer[i] = 0。
否则 answer[i] = 栈顶索引 - 当前索引。
*/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if (st.size()) {
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};
