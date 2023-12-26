class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        map<long long, int> mp;
        int ans = 0;
        for (auto p : coordinates) {
            int x = p[0], y = p[1];
            for (int a = 0; a <= k; a ++) {
                int xx = x ^ a, yy = y ^ (k - a);
                if (mp.count(1ll * xx * 1e6 + yy)) {
                    ans += mp[1ll * xx * 1e6 + yy];
                }
            }
            mp[1ll * x * 1e6 + y] ++;
        }
        return ans;
    }
};