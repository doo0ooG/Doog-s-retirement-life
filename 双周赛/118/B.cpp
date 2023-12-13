class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        n = hBars.size(), m = vBars.size();
        int ans = 1;
        for (int i = 0; i < n; i ++) {
            int j = i;
            while (j + 1 < n && hBars[j + 1] == hBars[j] + 1) {
                j ++;
            }

            for (int l = 0; l < m; l ++) {
                int r = l;
                while (r + 1 < m && vBars[r + 1] == vBars[r] + 1) {
                    r ++;
                }
                int len = min(j - i + 1, r - l + 1);
                // cout << j - i + 1 << " " << r - l + 1 << "\n";
                ans = max(ans, len + 1);
            }

            i = j;
        }
        return ans * ans;
    }
};