/*
题意：
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。

思路：
辅助栈。主栈正常存储所有元素，辅助栈同步存储每个时刻的最小值。
push 时，先将元素压入主栈，然后将当前最小值（新元素与辅助栈顶的较小者）压入辅助栈。
pop 时，两个栈同时弹出。
top 返回主栈栈顶，getMin 返回辅助栈栈顶。
*/


class MinStack {
public:
    stack<int> st1, st2;
    MinStack() {

    }

    void push(int val) {
        st1.push(val);
        if (st2.empty() || val <= st2.top()) {
            st2.push(val);
        } else {
            st2.push(st2.top());
        }
    }

    void pop() {
        st1.pop();
        st2.pop();
    }

    int top() {
        return st1.top();
    }

    int getMin() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
