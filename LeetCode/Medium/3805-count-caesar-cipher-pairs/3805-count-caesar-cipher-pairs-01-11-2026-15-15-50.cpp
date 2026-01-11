class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, long long> freq;

        for (string &s : words) {
            int shift = s[0] - 'a';
            string key;

            for (char c : s) {
                int diff = (c - 'a' - shift + 26) % 26;
                key.push_back('a' + diff);
            }

            freq[key]++;
        }

        long long ans = 0;
        for (auto &it : freq) {
            long long c = it.second;
            ans += c * (c - 1) / 2;
        }

        return ans;
    }
};