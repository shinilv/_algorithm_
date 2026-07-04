"""
题意：
https://atcoder.jp/contests/abc430/tasks/abc430_c

输入 n(1≤n≤3e5) a(1≤a≤n) b(1≤b≤n) 和长为 n 的字符串 s，只包含 'a' 和 'b'。

输出 s 有多少个子串 t，满足 t 至少有 a 个 'a'，至多有 b-1 个 'b'。

思路：
三指针做法，枚举位置i作为字串右端点，  对于每一个i
计算 [0 - lefta] 中满足s[k - i] 中'a'的数量大于A的k的数量
计算 [leftb - i] 中满足s[k - i] 中'b'的数量小于B的k的数量
leftb - lefta之间的区间就是i对应满足条件的左端点
ans += max(0, leftb - lefta + 1)

"""

n, a, b = map(int, input().split())
s = input()

lefta, leftb = 0, 0
cnta, cntb = 0, 0
ans = 0
for i, ch in enumerate(s):
    if ch == 'a':
        cnta += 1
    else:
        cntb += 1

    while cnta >= a:
        if s[lefta] == 'a':
            cnta -= 1
        lefta += 1
    while cntb >= b:
        if s[leftb] == 'b':
            cntb -= 1
        leftb += 1
    ans += max(0, lefta - leftb) # 这里lefta位置是不满足条件的，所以相当((lefta - 1) - leftb + 1)
print(ans)
