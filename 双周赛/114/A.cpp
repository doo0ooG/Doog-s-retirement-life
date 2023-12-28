class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        vector<int> vis(n + 1, 0);
        auto ok = [&]() {
            for (int i = 1; i <= k; i ++) {
                if (!vis[i]) {
                    return false;
                }
            }
            return true;
        };

        for (int i = n - 1; i >= 0; i --) {
            ans++;
            vis[nums[i]] = true;
            if(ok()) {
                return ans;
            }
        }
        return ans;
    }
};