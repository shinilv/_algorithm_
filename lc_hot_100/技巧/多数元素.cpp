/*
题意：
给定一个大小为 n 的数组 nums ，返回其中的多数元素。
多数元素是指在数组中出现次数大于 ⌊ n / 2 ⌋ 的元素。

数据范围：
n == nums.length
1 <= n <= 5 * 10^4
-10^9 <= nums[i] <= 10^9
题目数据保证多数元素一定存在。

思路：
由于这个元素的数量大于数组的一半，所以可以让这个多数元素
和其他元素进行抵消，最后留下一些元素一定是多数元素
可以设计一个flag表示一个元素x出现的次数，
编译数组 如果flag == 0给x重新赋值 x = nums[i]
否则 如果nums[i] == x flag += 1
    else flag -= 1
最后这个多数元素一定是x
*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int flag = 0, x = 0;
        for (int num : nums) {
            if (flag == 0) {
                x = num;
            }
            if (x == num) flag += 1;
            else flag -= 1;
        }
        return x;
    }
};
