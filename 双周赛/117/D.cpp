class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long ans = 0;
        vector<int> p;
        for (auto v : values) {
            for (auto item : v) {
                p.push_back(item);
            }
        }
        sort(p.begin(), p.end());
        for (int i = 1; i <= (int)p.size(); i ++) {
            ans += 1ll * i * p[i - 1];
        }
        return ans;
    }
};