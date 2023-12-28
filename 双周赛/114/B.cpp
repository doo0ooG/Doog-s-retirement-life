class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }
        int ans = 0;
        for (auto [x, c]: mp) {
            if (c == 1) {
                return -1;
            } else {
                while (c && c % 3) {
                    c -= 2;
                    ans ++;
                }
                if (c && c % 3 == 0) {
                    ans += c / 3;
                }
            }
        }

        return ans;
    }
};