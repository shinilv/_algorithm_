/*
题意：
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。

思路：
单调栈。对于每个柱子，找到其左边第一个比它矮的柱子（左边界）和右边第一个比它矮的柱子（右边界），
则以当前柱子高度为高的最大矩形宽度 = 右边界 - 左边界 - 1。
用一个栈维护单调递增的索引，当遇到比栈顶小的柱子时，弹出栈顶并计算以该高度为高的最大面积。
右边界是当前遍历到的位置，左边界是弹出后新的栈顶。
最后将高度为 0 的哨兵追加到末尾，清空栈中剩余元素。
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        vector<int> st;
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (st.size() && heights[st.back()] >= heights[i]) {
                int h = st.back();
                st.pop_back();
                int w = st.size() ? i - st.back() - 1 : i;
                ans = max(ans, h * w);
            }
            st.push_back(i);
        }
        return ans;
    }
};
