class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        
        auto cmp = [&](string s, string t) {
            int res = 0;
            for (int i = 0; i < s.size(); i ++) {
                res += s[i] != t[i];
            }
            return res == 1;
        };
        
        vector<vector<string>> dp(n + 1, vector<string>());
        for (int i = 1; i <= n; i ++) {
            auto word = words[i - 1];
            auto group = groups[i - 1];
            dp[i].push_back(word);
            for (int j = 1; j < i; j ++) {
                auto preWord = words[j - 1];
                auto preGroup = groups[j - 1];

                if (group != preGroup && word.size() == preWord.size() && cmp(word, preWord)) {
                    if (dp[i].size() < dp[j].size() + 1) {
                        dp[i] = dp[j];
                        dp[i].push_back(word);
                    }
                }
            }
        }
        vector<string> ans;
        for (auto dpi : dp) {
            if (dpi.size() > ans.size()) {
                ans = dpi;
            }
        }
        return ans;
    }
};