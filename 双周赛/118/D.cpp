class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        
        int n = nums.size(), front = 0, rear = 0;

        vector<long long> f(n + 1, 0), last(n + 1, 0), s(n + 1, 0), q(n + 1, 0);
        
        for (int i = 1; i <= n; i ++) {
            s[i] = s[i - 1] + nums[i - 1];

            while (front < rear && s[q[front + 1]] + last[q[front + 1]] <= s[i]) {
                front ++;
            }

            f[i] = f[q[front]] + 1;
            last[i] = s[i] - s[q[front]];

            while (front <= rear && s[q[rear]] + last[q[rear]] >= s[i] + last[i]) {
                rear --;
            } 
            q[++rear] = i;
        }
        return f[n];
    }
};