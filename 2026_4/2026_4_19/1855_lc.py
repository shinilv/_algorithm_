"""
题意：
给你两个非递增数组 nums1 和 nums2，让你找一对下标 (i, j)，满足 i <= j 且 nums1[i] <= nums2[j]。
在所有满足条件的下标对里，求最大的距离 j - i，如果一个都没有就返回 0。
思路：
双指针，使用两个指针 i, j 指向两个数组的结尾
如果nums1[i] <= nums2[j], 则 i--， 循环执行此操作
注意，上面循环一次都没有执行的话，不能更新ans
"""

class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        i, j = len(nums1) - 1, len(nums2) - 1
        ans = 0
        f = 0
        while i >= 0 and j >= 0:
            while i >= 0 and nums1[i] <= nums2[j]:
                f = 1
                i -= 1
            if f:
                ans = max(ans, j - i - 1)
            j -= 1
            f = 0
        return ans