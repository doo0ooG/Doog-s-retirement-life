class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n = word.size();
        int ans = 0;

        for (int i = 0; i < n; i ++) {
            int j = i;
            while (j + 1 < n && abs(word[j] - word[j + 1]) <= 1) {
                j ++;
            }
            ans += (j - i + 1) / 2;
            // cout << i <<" " << j << "\n";
            i = j;
        }

        return ans;
    }
};