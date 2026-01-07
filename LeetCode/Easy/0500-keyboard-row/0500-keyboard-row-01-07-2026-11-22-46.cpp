class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string r1 = "qwertyuiopQWERTYUIOP";
        string r2 = "asdfghjklASDFGHJKL";
        string r3 = "zxcvbnmZXCVBNM";

        vector<string> result;

        for (string& word : words) {
            int c1 = 0, c2 = 0, c3 = 0;
            bool valid = true;

            for (char ch : word) {
                if (r1.find(ch) != string::npos) c1++;
                else if (r2.find(ch) != string::npos) c2++;
                else if (r3.find(ch) != string::npos) c3++;
                if ((c1 && c2) || (c1 && c3) || (c2 && c3)) {
                    valid = false;
                    break;
                }
            }

            if (valid) result.push_back(word);
        }

        return result;
    }
};