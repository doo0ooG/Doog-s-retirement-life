class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int ans = 0;
        int a = -1;
        for (auto i : nums) {
            a &= i;
            if (a == 0) {
                ans ++;
                a = -1;
            }
        }
        return ans ? ans : 1;
    }
};