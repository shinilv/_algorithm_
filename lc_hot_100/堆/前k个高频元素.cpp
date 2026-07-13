/*
题意：
给你一个整数数组 nums 和一个整数 k ，
请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

思路：
1. 使用 unordered_map 统计每个元素出现的次数。
2. 创建 n + 1 个桶：
   bucket[i] 存储出现次数恰好为 i 的所有元素。
3. 从频率 n 开始倒序遍历桶，把元素加入答案。
4. 当答案数量达到 k 时返回。

因为每个元素最多出现 n 次，所以频率范围是 [1, n]。
时间复杂度：平均 O(n)
空间复杂度：O(n)
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto x : nums) mp[x] += 1;
        int n = nums.size();
        vector<vector<int>> vec(n + 1);
        for (auto [x, cnt] : mp) {
            vec[cnt].push_back(x);
        }
        vector<int> ans;
        for (int cnt = n; cnt >= 1; cnt--) {
            for (auto x : vec[cnt]) {
                ans.push_back(x);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return {};
    }
};
