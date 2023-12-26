class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, bool>>> g(n, vector<pair<int, bool>>());
        vector<int> ans(n, 0);
        for (auto edge : edges) {
            int a = edge[0], b = edge[1];
            g[a].push_back({b, true});
            g[b].push_back({a, false});
        }
        function<void(int, int)> dfs = [&](int u, int fa) {
            ans[u] = 0;
            for (auto [v, flag] : g[u]) if(v != fa) {
                dfs(v, u);
                ans[u] += ans[v] + !flag;
            }
        };
        dfs(0, 0);
        function<void(int, int, bool)> dfs1 = [&](int u, int fa, bool faFlag) {
            if (u) {
                if (faFlag) ans[u] = ans[fa] + 1;
                else ans[u] = ans[fa] - 1;
            }
            for (auto [v, flag] : g[u]) if(v != fa) {
                dfs1(v, u, flag);
            }
        };
        dfs1(0, 0, 0);
        return ans;
    }
};