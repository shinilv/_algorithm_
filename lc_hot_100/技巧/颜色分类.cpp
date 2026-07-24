/*
题意：
给定一个数组 nums 中的颜色 0、1、2（分别代表红色、白色、蓝色），
原地将它们排序，使相同颜色的元素相邻，并按照红色、白色、蓝色的顺序排列。
不能使用代码库提供的排序函数。

数据范围：
n == nums.length
1 <= n <= 300
nums[i] 为 0、1 或 2

思路：
荷兰国旗算法
*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, cur = 0, r = nums.size() - 1;
        while (cur <= r) {
            if (nums[cur] == 0) {
                swap(nums[cur], nums[l++]);
            } else if (nums[cur] == 2) {
                swap(nums[cur], nums[r--]);
            }
            cur++;
        }
    }
};
