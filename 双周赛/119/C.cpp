class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        int left = 0, n = nums.size();
        map<int, int> count;
        for (int i = 0; i < n; i ++) {
            auto &cnt = count[nums[i]];
            cnt ++;
            while (cnt > k) {
                count[nums[left]] --;
                left ++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};