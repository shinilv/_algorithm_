/*
题意：
给定一个整数数组 nums ，将其重新排列成字典序中的下一个更大的排列。
如果不存在下一个更大的排列，则将其改为升序排列（最小排列）。
必须原地修改，只允许使用常数额外空间。

数据范围：
1 <= nums.length <= 100
0 <= nums[i] <= 1000

1 3 2 4 5
1 4 3 2 5
1 3 5 4 2

思路：
要寻找比当前排列字典序都大的排列中的最小的排列
所以如果存在最后一个nums[i] < nums[i + 1]， 那nums[i]前面的的位置
的数都不能改变。
然后找到nums[j] 其中j > i nums[j] > nums[i] j最靠右的位置
因为这时候[i + 1, n) 是递减的，所以让nums[i]最小，只需要j最靠右即可
然后swap(nums[i], nums[j])
反转[i + 1, n)
*/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            int j = n - 1;
            while (nums[j] <= nums[i]) j--;
            swap(nums[j], nums[i]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};
