#include <bits/stdc++.h>
using namespace std;

/*
题目：3878. 统计好字数粗
题意：给一个数组a，统计满足条件的子数组数量。
条件是：子数组按位或和的结果存在于子数组中。
思路：
考虑单调栈 + 贡献
对于数组中的每一个数，计算包含这个数的子数组有多少个
核心代码：l[i]表示 a[l[i] + 1], a[l[i] + 2], ... a[i] 的按位或结果 = a[i]

stack<int> st;
st.push(-1); // 哨兵
for (int i = 0; i < n; i++) {
    int x = nums[i];
    while (st.size() > 1 && (nums[st.top()] | x) == x) {
        st.pop();
    }
    l[i] = st.top(); // nums[left[i]] 不是 x 的子集
    st.push(i);
}

然后再去求一遍 i 右边的r[i]， 但是需要加一个判断
while (st.size() > 1 && nums[st.top()] != x && (nums[st.top()] | x) == x)
nums[st.top()] != x， 这样可以防止子数组重复统计  (是在防止“相同值之间互相弹栈”，从而避免同一类区间被重复计数)
*/

class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int> l(n);
        stack<int> st;
        st.push(-1); // 哨兵
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (st.size() > 1 && (nums[st.top()] | x) == x) {
                st.pop();
            }
            l[i] = st.top(); // nums[l[i]] 不是 x 的子集
            st.push(i);
        }
        st = stack<int>();
        st.push(n);
        for (int i = n - 1; i >= 0; i--) {
            int x = nums[i];
            while (st.size() > 1 && nums[st.top()] != x && (nums[st.top()] | x) == x) {
                st.pop();
            }
            int r = st.top();
            st.push(i);
            ans += 1LL * (i - l[i]) * (r - i);
        }
        return ans;
    }
};