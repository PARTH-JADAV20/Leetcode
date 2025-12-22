class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result = "";
        int m = part.size();

        for (char c : s) {
            result.push_back(c);

            if (result.size() >= m &&
                result.substr(result.size() - m) == part) {
                result.erase(result.size() - m);
            }
        }
        return result;
    }
};