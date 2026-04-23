"""
题意：
对每个下标 i，找出所有与 nums[i] 相等且下标不等于 i 的位置 j，
把这些位置与 i 的距离 |i-j| 全部加起来，作为 arr[i]。
思路：
考虑吧所有相同的数分到同一个组
这样考虑单个数组 a，a中表示元素相等的下标集合
那么 ans[a[0]] 就等于 a[i] - a[0] for i in range(len(a))
那计算ans[a[1]] 就不需要重复这样计算了
可以看到 ans[a[1]] 和 ans[a[0]] 的关系，有一个数的距离变大了 a[1] - a[0]，有n - 1 个
数的距离减小了 a[1] - a[0]。推广到 ans[a[i]] 和 ans[a[i - 1]] 那就是 有 i 个数距离
增加了 a[i] - a[i - 1], 有n - i 个数距离减小了 a[i] - a[i - 1]
所以：令 x = a[i] - a[i - 1], ans[a[i]] = ans[a[i - 1]] + (i * x - (n - i) * x)  
"""

class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        g = defaultdict(list)
        for i, x in enumerate(nums):
            g[x].append(i)
        ans = [0] * len(nums)
        for _, a in g.items():
            n = len(a)
            s0 = sum(x - a[0] for x in a)
            ans[a[0]] = s0
            for i in range(1, n):
                s0 = s0 + (2 * i - n) * (a[i] - a[i - 1])
                ans[a[i]] = s0
        return ans
