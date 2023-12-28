class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        long long tmp = 0;
        int ans = 0;
        vector<vector<int>> g(n, vector<int>());
        for (auto edge : edges) {
            auto a = edge[0], b = edge[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        function<long long(int, int)> dfs = [&](int u, int fa) -> long long {
            long long res = values[u];
            for (auto v : g[u]) if (v != fa) {
                res += dfs(v, u);
            }
            if (res % k == 0) {
                // cout << u << " " << tmp << "\n";
                ans ++;
                res = 0;
            } 
            return res;
        };
        dfs(0, 0);
        return ans;
    }
};