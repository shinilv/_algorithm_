/*
题意：
给定一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
你最多只能完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
你不能在买入股票前卖出股票。

数据范围：
1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4

思路：
从左往右遍历，维护 minPrice（历史最低价）和 maxProfit（最大利润）。
对于每一天，先用当前价格减去历史最低价更新最大利润，再用当前价格更新最低价。
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {

    }
};
