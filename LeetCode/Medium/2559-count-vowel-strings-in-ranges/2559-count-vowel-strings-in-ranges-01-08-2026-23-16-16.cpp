class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();
        vector<int> prefixCnt(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixCnt[i + 1] = prefixCnt[i];
            if (vowels.count(words[i][0]) && vowels.count(words[i].back())) {
                prefixCnt[i + 1]++;
            }
        }

        vector<int> res;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            res.push_back(prefixCnt[r + 1] - prefixCnt[l]);
        }

        return res;
    }
};