using ll = long long;
class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& a) {
        ll ans = 0;
        int n = a.size();
        int l = 0;
        while (l < n - 1 && a[l] < a[l + 1]) {
            ++l;
        }
        if (l == n - 1) {
            return 1ll * n * (n + 1) / 2;
        }

        ans += l + 2;
        int r = n - 1;
        while (r > 0 && (r == n - 1 || a[r] < a[r + 1])) {
            while (l >= 0 && a[l] >= a[r]) {
                --l;
            }
            ans += l + 2;
            --r;
        }
        return ans;
    }
};