class Solution {
public:
    void makecombo(string &digits, int i, string temp,
                   vector<string> &ans, 
                   unordered_map<char, string> &lettermap) {
        
        if(i == digits.length()) {
            ans.push_back(temp);
            return;
        }

        string letters = lettermap[digits[i]];
        for(char letter : letters)
            makecombo(digits, i + 1, temp + letter, ans, lettermap);
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if(digits.length() == 0)
            return ans;

        unordered_map<char, string> lettermap = {
            {'2', "abc"}, 
            {'3', "def"},
            {'4', "ghi"}, 
            {'5', "jkl"},
            {'6', "mno"}, 
            {'7', "pqrs"},
            {'8', "tuv"}, 
            {'9', "wxyz"}
        };

        makecombo(digits, 0, "", ans, lettermap);
        return ans;
    }
};