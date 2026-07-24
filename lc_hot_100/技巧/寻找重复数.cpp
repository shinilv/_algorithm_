/*
题意：
给定一个包含 n + 1 个整数的数组 nums ，其中每个整数都在 [1, n] 范围内，
证明至少存在一个重复的数字。如果只有一个重复的数字，找出这个重复的数字。

思路：
方法一（快慢指针）：将数组视为链表，nums[i] 表示从下标 i 指向的下个节点。
由于存在重复数字，链表中必然有环，环的入口即为重复数字。
用快慢指针找环入口：先让快慢指针相遇，再将一个指针放回起点，同步移动直到相遇。
a

*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
