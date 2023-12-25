class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i + 1 < n; i += 2) {
            ans += s[i] != s[i + 1];
        }
        return ans;
    }
};