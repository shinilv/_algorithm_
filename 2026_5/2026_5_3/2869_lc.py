
"""
题意：统计[l, r] 中满足条件的数，这个数的数位具有单调性，或数位的和满足这个要求
"""
class Solution:
    def is_good(self, s: int) -> bool:
        if s < 100:
            return s // 10 != s % 10
        return 1 < s // 10 % 10 < s % 10
    def countFancy(self, l: int, r: int) -> int:
        def calc(s:str) -> int:
            n = len(s)
            # 这里是关键，st表示一些状态 0表示至多填了一个数，
            #1表示当前单增，2表示单减，3表示不是好数
            # 这样就转化为了经典数位dp
            @cache
            def dfs(u:int, d_sum:int, pre:int, st:int, is_up:int) -> int:
                if u == n:
                    return 1 if st != 3 or self.is_good(d_sum) else 0
                d = int(s[u]) if is_up else 9
                res = 0
                for i in range(d + 1):
                    new_st = st
                    if st == 0:
                        if pre > 0:
                            if i > pre:
                                new_st = 1
                            elif i < pre:
                                new_st = 2
                            else:
                                new_st = 3
                    elif st == 1:
                        if i <= pre:
                            new_st = 3
                    elif st == 2:
                        if i >= pre:
                            new_st = 3
                    res += dfs(u + 1, d_sum + i, i, new_st, is_up and i == d)
                return res
            return dfs(0, 0, 0, 0, True)
        return calc(str(r)) - calc(str(l - 1))