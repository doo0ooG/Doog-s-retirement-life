class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        map<int, int> cnt; 
        int mx = 0;
        for (auto num : nums) {
            cnt[num]++;
            mx = max(mx, cnt[num]);
        }
        if (mx > n / 2) {
            return n - 2 * (n - mx);
        } else {
            if (n & 1) {
                return 1;
            } else {
                return 0;
            }
        }
        return 0;
    }
};