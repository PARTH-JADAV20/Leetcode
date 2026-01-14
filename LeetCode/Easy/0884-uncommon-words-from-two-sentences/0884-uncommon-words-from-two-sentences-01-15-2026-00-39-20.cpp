class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;
        istringstream ss(s1 + " " + s2);
        string w;
        while (ss >> w) {
            count[w]++;
        }

        vector<string> res;
        for (auto& [word, freq] : count) {
            if (freq == 1) {
                res.push_back(word);
            }
        }

        return res;
    }
};