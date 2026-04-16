class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        n = len(nums)
        idx = defaultdict(list)
        for i, x in enumerate(nums):
            idx[x].append(i)
        for _, p in idx.items():
            i0 = p[0]
            p.insert(0, p[-1] - n)
            p.append(i0 + n)
        ans = []
        for q in queries:
            arr = idx[nums[q]]
            if len(arr) == 3:
                ans.append(-1)
                continue
            pos = bisect.bisect_left(arr, q)
            ans.append(min(arr[pos] - arr[pos - 1], arr[pos + 1] - arr[pos]))
        return ans