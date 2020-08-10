//
// Created by Zhao on 2020/8/10.
//

class Solution {
public:
    int splitArray(vector<int>& nums) {
        int n = nums.size(), m = *max_element(nums.begin(), nums.end());
        vector<int> max_factor(m + 1, 0), prime_dp(m + 1, n);
        for (int i = 2; i <= m; ++i) {
            if (!max_factor[i]) {
                for (int j = i; j <= m; j += i) {
                    max_factor[j] = i;
                }
            }
        }
        int ans = 0;
        for (int x: nums) {
            int curr_ans = n;
            for (; x != 1; x /= max_factor[x]) {
                curr_ans = min(curr_ans, 1 + (prime_dp[max_factor[x]] = min(prime_dp[max_factor[x]], ans)));
            }
            ans = curr_ans;
        }
        return ans;
    }
};