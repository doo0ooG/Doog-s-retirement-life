class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1e9));
        for (int i = 0; i <= n; i ++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; i ++) {
            int v = nums[i - 1];
            for (int j = 0; j <= target; j ++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= v) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - v] + 1);
                }
            }
        }
        return max(-1, dp[n][target]);
    }
};