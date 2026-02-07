class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        int freq[2] = {0, 0}; 

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == 'a') {
                if (freq[1] > 0) {
                    dp[i] = min(dp[i - 1] + 1, freq[1]);
                } else {
                    dp[i] = dp[i - 1];
                }
                freq[0]++;
            } else {
                freq[1]++;
                dp[i] = dp[i - 1];
            }
        }
        return dp[n];
    }
};
