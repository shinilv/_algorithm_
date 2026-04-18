"""
题意：
给你若干二进制片段，第 i 个片段由 nums1[i] 个连续的 1 和 nums0[i] 个连续的 0 组成。
你可以任意重排这些片段的顺序，要求拼接后得到的整个二进制数尽可能大，

思路：
考虑贪心，首先最左面开始的一段字符串一定是 '1' 越多越好
然后 '1' 相同的情况下一定是 '0' 越少越在左面，结果才会越大
"""

# wa 代码
class Solution:
    def maxValue(self, nums1: list[int], nums0: list[int]) -> int:
        n = len(nums1)
        a = []
        for i in range(n):
            a.append((nums1[i], -nums0[i]))
        a.sort(reverse=True)
        ans, cnt = 0, 1
        MOD = 1000000007
        for i in range(n - 1, -1, -1):
            for j in range(-a[i][1]):
                cnt = cnt * 2 % MOD
            for j in range(a[i][0]):
                ans = (ans + cnt) % MOD
                cnt = cnt * 2 % MOD
        return ans
"""
以上代码是贪心的实现，但是这里会忽略一种特殊情况
当 nums0[i] 等于0 的时候，这个串应该放到最左面才是最优的
"""
# ac代码
class Solution:
    def maxValue(self, nums1: list[int], nums0: list[int]) -> int:
        n = len(nums1)
        a = []
        left = 0
        for i in range(n):
            if nums0[i] == 0:
                left += nums1[i]
                continue
            a.append((nums1[i], -nums0[i]))
        a.sort()
        ans, cnt = 0, 1
        MOD = 1000000007
        for i in range(len(a)):
            for j in range(-a[i][1]):
                cnt = cnt * 2 % MOD
            for j in range(a[i][0]):
                ans = (ans + cnt) % MOD
                cnt = cnt * 2 % MOD
        for j in range(left):
            ans = (ans + cnt) % MOD
            cnt = cnt * 2 % MOD
        return ans