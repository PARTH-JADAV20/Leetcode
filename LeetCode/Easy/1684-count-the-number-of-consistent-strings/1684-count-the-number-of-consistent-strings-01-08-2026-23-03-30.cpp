class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());

        int res = words.size();
        for (string& w : words) {
            for (char c : w) {
                if (allowedSet.find(c) == allowedSet.end()) {
                    res--;
                    break;
                }
            }
        }

        return res;
    }
};