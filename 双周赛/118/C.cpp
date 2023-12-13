class Solution {
public:

    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> f(n + 10, 0);
        for (int i = n; i >= 1; i --) {
            int res = 1e9;
            for (int j = i + 1; j <= min(n, i * 2 + 1); j ++) {
                res = min(res, f[j]);
            }
            f[i] = prices[i - 1] + (i * 2 >= n ? 0 : res);
        }
        return f[1];
    }
};