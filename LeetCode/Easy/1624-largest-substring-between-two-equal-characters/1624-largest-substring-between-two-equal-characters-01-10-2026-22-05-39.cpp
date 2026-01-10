class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> charIndex;
        int res = -1;

        for (int i = 0; i < s.size(); i++) {
            if (charIndex.find(s[i]) != charIndex.end()) {
                res = max(res, i - charIndex[s[i]] - 1);
            } else {
                charIndex[s[i]] = i;
            }
        }

        return res;
    }
};