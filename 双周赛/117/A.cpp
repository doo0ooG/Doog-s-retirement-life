class Solution {
public:
    long long C(int a) {
        return 2 > a ? 0 : 1ll * a * (a - 1) / 2;
    }
    long long distributeCandies(int n, int limit) {
        return C(n + 2) - 3 * C(n + 2 - limit - 1) + 3 * C(n + 2 - 2 * limit - 2) - C(n + 2 - 3 * limit - 3);
    }
};