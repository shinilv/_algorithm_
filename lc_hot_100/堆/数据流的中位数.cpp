/*
题意：
给你一个数据流，请你实时求出当前所有元素的中位数。
实现 MedianFinder 类：
- addNum(int num)：将数据流的整数 num 添加到数据结构中。
- findMedian()：返回当前所有元素的中位数。
数据范围：
- -10^5 <= num <= 10^5
- 当调用 findMedian() 时，数据结构中至少有一个元素
- addNum 和 findMedian 总共最多调用 5 * 10^4 次
思路：
参考这个很清楚的题解https://leetcode.cn/problems/find-median-from-data-stream/solutions/3015873/ru-he-zi-ran-yin-ru-da-xiao-dui-jian-ji-4v22k/?envId=top-100-liked&envType=study-plan-v2

*/

class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> r;
    priority_queue<int, vector<int>, less<int>> l;
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (l.size() == r.size()) {
            r.push(num);
            l.push(r.top());
            r.pop();
        } else {
            l.push(num);
            r.push(l.top());
            l.pop();
        }
    }

    double findMedian() {
        double ans = l.top();
        if (l.size() == r.size()) {
            ans += r.top();
            ans /= 2;
        }
        return ans;
    }
};
