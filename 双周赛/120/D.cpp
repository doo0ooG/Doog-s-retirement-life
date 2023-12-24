using ll = long long;
class Solution {
public:
    vector<ll> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<ll> ans(n, 0ll);
        vector<vector<int>> g(n, vector<int>());
        vector<int> sz(n, 0);
        
        for (auto edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        function<pair<vector<ll>, vector<ll>>(int, int)> dfs = [&](int u, int fa) {
            vector<ll> res, mnRes;
            if (cost[u] > 0) res.push_back(cost[u]);
            if (cost[u] < 0) mnRes.push_back(cost[u]);
            sz[u] = 1;
            
            for (auto v : g[u]) if (v != fa) {
                auto getter = dfs(v, u);
                auto sonRes = getter.first;
                auto sonMn = getter.second;
                sz[u] += sz[v];

                for (auto i : sonRes) {
                    res.push_back(i);
                }
                for (auto i : sonMn) {
                    mnRes.push_back(i);
                }
                sort(mnRes.begin(), mnRes.end());
                sort(res.begin(), res.end());
                reverse(res.begin(), res.end());
                vector<ll> tmp1, tmp2;
                tmp1.push_back(res[0]);
                tmp1.push_back(res[1]);
                tmp1.push_back(res[2]);
                tmp2.push_back(mnRes[0]);
                tmp2.push_back(mnRes[1]);
                res = tmp1;
                mnRes = tmp2;
            }
            while (res.size() < 3) {
                res.push_back(0ll);
            }
            while (mnRes.size() < 2) {
                mnRes.push_back(0ll);
            }
            if (sz[u] < 3) {
                ans[u] = 1;
            } else {
                ans[u] = res[0] * res[1] * res[2];
                ans[u] = max(ans[u], mnRes[0] * mnRes[1] * res[0]);
            }
            return make_pair(res, mnRes);
        };
        dfs(0, 0);
        
        return ans;
    }
};