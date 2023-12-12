class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> vis1(110, 0), vis2(110, 0);
        vector<int> ans(2, 0);
        for (auto i : nums1) {
            vis1[i] = 1;
        }
        for (auto i : nums2) {
            vis2[i] = 1;
        }
        for (auto i :nums1) {
            if (vis2[i]) {
                ans[0] ++;
            } 
        }
        for (auto i : nums2) {
            if (vis1[i]) {
                ans[1] ++;
            } 
        }
        return ans;
    }
};