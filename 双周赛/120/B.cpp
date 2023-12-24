class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n =  nums.size();
        long long ans = -1;
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i ++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        for (int i = n; i >= 3; i --) {
            if (nums[i - 1] < pre[i - 1]) {
                // ans = max(ans, pre[i]);
                return pre[i];
            }
        }
        return ans;
    }
};