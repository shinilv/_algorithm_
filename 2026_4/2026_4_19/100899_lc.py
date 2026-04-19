"""
题意：
给定区间 [l, r] 和一个长度为 6 的路径串 directions（恰有 3 个 D 和 3 个 R）。
对每个数 x，把它补成 16 位十进制串后按行填入 4×4 网格，
从左上角按 directions 走出一条包含 7 个格子的路径；
如果路径上的数字序列是非递减的，就称 x 为好整数，求区间内好整数的个数。
1 <= l <= r <= 9e15
思路：
由于l, r 非常大，考虑转为16位字符串，不够的前面补0 去处理
首先解析 directions，得到这个10进制字符串，哪几位需要满足非递减

"""

class Solution:
    def countGoodIntegersOnPath(self, l: int, r: int, directions: str) -> int:
        pos = 0
        vis = [0] * 16
        for x in directions:
            if x == 'D':
                pos += 4
            else:
                pos += 1
        def calc(s:str) -> int:
            @cache
            def dfs(u:int, pre:int, is_up:bool) -> int:
                if u == 16:
                    return 1
                up = 9
                if is_up:
                    up = int(s[u])
                res = 0
                for i in range(0, up + 1):
                    if vis[u]:
                        if i >= pre:
                            res += dfs(u + 1, i, i == up)
                    else:
                        res += dfs(u + 1, pre, i == up)
                return res 
            # u 表示当前是第几位，pre是路径上的上一个数字，初始为-1， is_up表示前面是否都是最大，意为当前位置最大不能超过int(s[u])
            return dfs(0, -1, True)
        
        sl = str(l - 1)
        sl = '0' * (16 - len(sl)) + sl
        sr = str(r)
        sr = '0' * (16 - len(sr)) + sr
        return calc(sl) - calc(sr)
