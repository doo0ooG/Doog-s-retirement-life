

class Solution {
public:
    int dist[10][10];
    bool vis[10] = {0};
    int ans = 0;
    void dfs(int cur, int n, int maxDistance, vector<vector<int>>& roads) {
        if (cur == n) {
            for (int i = 0; i < n; i ++) {
                cout << vis[i] << " \n"[i == n - 1];
            }
            memset(dist, 0x3f, sizeof dist);
            for (int i = 0; i < n; i ++) {
                dist[i][i] = 0;
            }
            for (auto road :roads) {
                int a = road[0], b = road[1], c = road[2];
                dist[a][b] = dist[b][a] = min(dist[a][b], c);
            }
            //floyd
            for (int k = 0; k < n; k ++) {
                for (int i = 0; i < n; i ++) {
                    for (int j = 0; j < n; j ++) {
                        if (vis[i] || vis[j] || vis[k]) continue;
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }   
            bool success = true;
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < n; j ++) {
                    if (vis[i] || vis[j]) continue;
                    if (dist[i][j] > maxDistance) {
                        success = false;
                    }
                }
            }
            if (success) {
                ans ++;
            }
            
            return;
        }
        // 当前点不去除
        dfs(cur + 1, n, maxDistance, roads);
        // 当前点去除
        vis[cur] = true;
        dfs(cur + 1, n, maxDistance, roads);
        vis[cur] = false;
    }
   
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        dfs(0, n, maxDistance, roads);
        return ans;
    }
};