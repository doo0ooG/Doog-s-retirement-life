using ll = long long;
const ll mod = 1e9 + 7;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> last(1e5 + 5, 0);
        struct node {
            ll res;
            ll t;
        } tr[(n + 5) << 2];
        long long tmp = 0, ans = 0;

        function<void(int)> pushup = [&](int u) -> void {
            tr[u].res = tr[u << 1].res + tr[u << 1 | 1].res;
        };

        function<void(int, int, int, ll)> settag = [&](int u, int l, int r, ll t) -> void {
            // if(u==9) cout << "\ndebug # "<<tr[u].res << " " << tr[u].t << "\n";
            tr[u].res += (r - l + 1) * t;
            tr[u].t += t;
            // if(u==9) cout << "\ndebug # "<< tr[u].res << " " << tr[u].t << "\n";
        };

        function<void(int, int, int)> pushdown = [&](int u, int l, int r) -> void {
            if (tr[u].t) {
                int mid = (l + r) >> 1;
                settag(u << 1, l, mid, tr[u].t);
                settag(u << 1 | 1, mid + 1, r, tr[u].t);
                tr[u].t = 0;
            }
        };

        function<void(int, int, int)> build = [&](int u, int l, int r) -> void {
            if (l == r) {
                tr[u].res = tr[u].t = 0;
                return;
            } else {
                tr[u].res = tr[u].t = 0;
                int mid = (l + r) >> 1;
                build(u << 1, l, mid);
                build(u << 1 | 1, mid + 1, r);
                pushup(u);
            }
        };

        function<void(int, int, int, int, int, int)> modify = [&](int u, int l, int r, int ql, int qr, int t) -> void {
            if (l == ql && r == qr) {
                tr[u].t += t;
                tr[u].res += (ll)(r - l + 1) * t;
                return;
            } else {
                pushdown(u, l, r);
                int mid = (l + r) >> 1;
                if (qr <= mid) modify(u << 1, l, mid, ql, qr, t);
                else if (ql > mid) modify(u << 1 | 1, mid + 1, r, ql, qr, t);
                else {
                    modify(u << 1, l, mid, ql, mid, t);
                    modify(u << 1 | 1, mid + 1, r, mid + 1, qr, t);
                }
                pushup(u);
            }
        };

        function<ll(int, int, int, int, int)> query = [&](int u, int l, int r, int ql, int qr) -> ll {
            if (l == ql && r == qr) {
                return tr[u].res;
            } else {
                pushdown(u, l, r);
                int mid = (l + r) >> 1;
                if (qr <= mid) return query(u << 1, l, mid, ql, qr);
                else if (ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
                else {
                    ll res = 0;
                    res += query(u << 1, l, mid, ql, mid);
                    res += query(u << 1 | 1, mid + 1, r, mid + 1, qr);
                    return res % mod;
                }
            }
        };

        build(1, 1, n);
        // cout << query(1, 1, n, 1, n) << " first\n";
        // modify(1, 1, n, 1, n);
        // cout << query(1, 1, n, 1, 2) << " first\n";
        // modify(1, 1, n, 1, 2); 
        // cout << query(1, 1, n, 1, n) << " first\n";
        // for (int i = 1; i <= 5; i ++) {
        //     cout << tr[i].res << " " << tr[i].t << "\n";
        // }

        for (int i = 1; i <= n; i ++) {
            int digit = nums[i - 1];
            int l = last[digit] + 1, r = i;
            // cout << l << " " << r << " # ";
            tmp = (tmp + 2 * query(1, 1, n, l, r) % mod + (r - l + 1)) % mod;
            // cout << query(1, 1, n, l, r) << "\n";
            modify(1, 1, n, l, r, 1);
            ans = (ans + tmp) % mod;
            last[digit] = i;
            // for (int i = 1; i <= 17; i ++) {
            //     cout << tr[i].res << " " << tr[i].t << "\n";
            // }
            // if (i == 4) break;
            // cout << "\n  +++++++++++  \n";
        }

        // for (int i = 1; i <= 17; i ++) {
        //     cout << tr[i].res << " " << tr[i].t << "\n";
        // }

        return ans;
    }
};