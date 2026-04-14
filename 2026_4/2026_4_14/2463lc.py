# 本题考查DP + 贪心
# 先将机器人和工厂按照位置排序，工厂按照位置排序后
# 这里贪心结论是 一个工厂修理一段连续的机器人（已经排序好的）是最优的
# 设dfs(r, f, cnt)表示当前修理了r个机器人，当前在第f个工厂，当前工厂还可以修理cnt个机器人
# 那么如果当前工厂还可以修理机器人，那么可以选择修理当前机器人，或者不修理当前机器人
# 如果不修理当前机器人，那么就跳过当前工厂，去下一个工厂修理当前机器人
# 如果修理当前机器人，那么就修理当前机器人，当前工厂还可以修理cnt - 1个机器人，
# 修理当前机器人需要的距离是abs(factory[f][0] - robot[r])
# 如果当前工厂已经不能修理机器人了，那么就只能跳过当前工厂，去下一个工厂修理当前机器人
# 递归的边界条件是，如果当前修理了所有的机器人，那么返回0，
# 如果当前工厂已经全部用完但是机器人没有没全部修理，那么返回inf

class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        robot.sort()
        factory.sort()
        n, m = len(robot), len(factory)
        @lru_cache(None)
        def dfs(r:int, f:int, cnt:int) -> int:
            # dfs(r, f, cnt)表示当前修理了r个机器人，当前在第f个工厂，当前工厂还可以修理cnt个机器人
            if cnt < 0:
                return float("inf")
            if r == n:
                return 0
            if f == m:
                return float("inf")
            t = abs(factory[f][0] - robot[r])
            # 这里如果当前已经是最后一个工厂，就只能使用这个工厂去休息剩下的所有机器人了，
            # 注意需要加一个递归边界条件，如果cnt < 0了，说明最后一个工厂不够用，那么就返回inf
            if f == m - 1:
                return dfs(r + 1, f, cnt - 1) + t
            res = dfs(r, f + 1, factory[f + 1][1])
            if cnt > 0:
                res = min(res, dfs(r + 1, f, cnt - 1) + t)
            return res
        return dfs(0, 0, factory[0][1])