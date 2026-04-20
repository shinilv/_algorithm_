"""
题意：
给一个数组nums，找出最大的abs(i - j) 使得  nums[i] != nums[j]

思路1：
记录每个颜色的最小和最大位置
逐个比较每个颜色的最小位置和当前最大的右边界，最大位置和当前最小的左边界

思路2：
脑筋急转弯，如果nums[0] != nums[-1]，直接返回len(nums) - 1
否则，找到第一个和nums[0]不同的元素，记录和最后一个元素的距离d1
和最后一个和nums[0]不同的元素，记第一个元素的距离d2
返回max(d1, d2)
"""

# 思路1
class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        mp = defaultdict(list)
        for i, x in enumerate(colors):
            mp[x].append(i)
        ans = 0
        l, r = len(colors), -1
        for k, v in mp.items():
            ans = max(ans, max(r - v[0], v[-1] - l))
            l = min(l, v[0])
            r = max(r, v[-1])
        return ans
    
# 思路2
class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        n = len(colors)
        if colors[0] != colors[-1]:
            return n - 1
        l, r = 1, n - 2
        while colors[l] == colors[0]:
            l += 1
        while colors[r] == colors[0]:
            r -= 1
        return max(r, n - l - 1)