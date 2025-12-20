class Solution {
public:
    string reverseWords(string s) {
        vector<string> temp;
        string str = "";

        for (char c : s) {
            if (c == ' ') {
                if (!str.empty()) {
                    temp.push_back(str);
                    str = "";
                }
            } else {
                str += c;
            }
        }

        if (!str.empty()) temp.push_back(str);

        string ans = "";
        for (int i = temp.size() - 1; i >= 0; i--) {
            ans += temp[i];
            if (i != 0) ans += " ";
        }

        return ans;
    }
};