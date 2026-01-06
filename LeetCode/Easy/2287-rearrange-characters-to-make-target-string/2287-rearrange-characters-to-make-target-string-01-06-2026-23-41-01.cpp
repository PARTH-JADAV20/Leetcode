class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> countText;
        for (char c : s) {
            countText[c]++;
        }
        unordered_map<char, int> freq ;
        for (char c : target) {
            freq[c]++;
        }
        int res = s.length();
        for (auto& entry : freq) {
            res = min(res, countText[entry.first] / entry.second);
        }
        return res;
    }
};