class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, pos = 0;
        for (int i = 0; i < n - 1; i ++) {
            if (nums[i] > nums[i + 1]) {
                cnt ++;
                pos = i + 1;
            }
        }
        if (cnt == 0) {
            return cnt;
        } 
        if (cnt > 1) {
            return -1;
        }
        if (nums[0] > nums[n - 1]) {
            return n - pos;
        } else {
            return -1;
        }
    }
};