/*
题意：
给定一个非负整数数组 nums ，你最初位于数组的第一个下标。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。

数据范围：
1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5

思路：
维护 maxReach 表示从起点出发最多能到达的最远位置。
从左到右遍历，如果当前下标 i 超过 maxReach，说明无法到达 i，返回 false。
否则用 i + nums[i] 更新 maxReach，若 maxReach >= 末尾则提前返回 true。
*/


class Solution {
public:
    bool canJump(vector<int>& nums) {

    }
};
