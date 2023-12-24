using ll = long long;
const ll p = 1e9 + 7;

class Solution {
public:
    ll qmi(ll a, ll b) {
        ll res = 1;
        a %= p;
        while (b) {
            if (b & 1) (res *= a) %= p;
            (a *= a) %= p;
            b >>= 1;
        }
        return res;
    }

    int stringCount(int n) {
        ll ans = 0;
        ans = (ans + 3 * qmi(25, n) % p) % p;
        ans = (ans + n * qmi(25, n - 1) % p) % p;

        ans = ((ans - 3 * qmi(24, n)) % p + p) % p; 
        ans = ((ans - 2 * n * qmi(24, n - 1) % p) % p + p) % p; 

        
        ans = (ans + qmi(23, n) % p) % p;
        ans = (ans + n * qmi(23, n - 1) % p) % p;

        return ((qmi(26, n) - ans) % p + p) % p;
    }
};