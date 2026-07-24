/*
题意：
给定一个非空整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。
找出那个只出现了一次的元素。

数据范围：
1 <= nums.length <= 3 * 10^4
-3 * 10^4 <= nums[i] <= 3 * 10^4
数组中所有元素除了一个只出现一次的之外，其余都出现两次。
*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto x : nums) {
            ans ^= x;
        }
        return ans;
    }
};
