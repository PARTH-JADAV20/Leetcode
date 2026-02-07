class Solution {
public:
    int balancedString(string s) {
        const int n = s.length(), k = n / 4;
        int freq[26] = {0};
        for(int i = 0, n = s.length(); i < n; ++i) ++freq[s[i] - 'A'];
        int res = n;
        for(int i = 0, j = 0; j < n; ++j){
            --freq[s[j] - 'A'];
            while (i < n && max({freq['Q' - 'A'], freq['W' - 'A'], freq['E' - 'A'], freq['R' - 'A']}) <= k) {
                res = min(res, j - i + 1);
                ++freq[s[i++] - 'A'];
            }
        }
        return res;
    }
};