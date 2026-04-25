"""
题意：
给一个数组d，使得数组a的所有元素时非递减的，并且 a[i] 的数位和 与 d[i] 相等
求满足条件的数组a的数量，对结果取模 10^9 + 7

思路：
由于 d[i] <= 50 && d[i] >= 0， 范围比较小，可以把每一个d[i]，找出
可以构成的 0 - 5000 的所有数
这里做一个预处理
cnt = [list() for _ in range(51)]
for i in range(5001):
    s = sum(map(int, str(i)))
    if s <= 50:
        cnt[s].append(i)

然后考虑dp
dp[i][j] 表示 第 i 个位置的数字时应 构成的第j个数（cnt[d[i]][j]） 这时候的情况个数
dp[0][0] = 1
dp[i][j] = sum(dp[i - 1][j] # 这里当dp[i - 1][j]对应的数小于等于dp[i][j])，可一贪心的优化一下
具体看代码

"""
cnt = [list() for _ in range(51)]
for i in range(5001):
    s = sum(map(int, str(i)))
    if s <= 50:
        cnt[s].append(i)

class Solution:
    def countArrays(self, digitSum: list[int]) -> int:
        n = len(digitSum)
        dp = [list() for _ in range(n + 1)]
        pre = [0]
        dp[0].append(1)
        MOD = 1000000007
        for i in range(1, n + 1):
            t, idx = 0, 0
            for j in cnt[digitSum[i - 1]]:
                while idx < len(pre) and pre[idx] <= j:
                    t += dp[i - 1][idx]
                    t %= MOD
                    idx += 1
                dp[i].append(t)
            pre = cnt[digitSum[i - 1]]
        return sum(dp[n]) % MOD
