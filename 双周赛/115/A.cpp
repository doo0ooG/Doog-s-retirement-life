class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        int n = words.size();
        int continious = 0;
        vector<int> ans, digitArr;

        for (auto word : words) {
            if (word[0] != 'p') {
                int digit = stoi(word);
                digitArr.push_back(digit);
                continious = 0;
            } else {
                continious ++;
                if (digitArr.size() < continious) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(digitArr[digitArr.size() - continious]);
                }
            }
        }

        return ans;
    }
};