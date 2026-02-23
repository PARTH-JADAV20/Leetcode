class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (k > n) return false;

        unordered_set<string> freq;

        for (int i = 0; i + k <= n; i++) {
            freq.insert(s.substr(i, k));
        }

        return freq.size() == (1 << k);
    }
};
