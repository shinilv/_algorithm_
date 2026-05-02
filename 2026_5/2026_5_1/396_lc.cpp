/*
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = 0, n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            ans += i * nums[i];
            sum += nums[i];
        }
        int t = ans;
        for (int i = n - 1; i >= 0; i--) {
            t -= nums[i] * (n - 1);
            t += sum - nums[i];
            ans = max(ans, t);
        }
        return ans;
    }
};