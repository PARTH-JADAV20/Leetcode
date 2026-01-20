class Solution {
public:
    string reverseWords(string s) {
        int n =  s.size();
        string ans = "";
        string temp ="";

        for(int i = n-1; i>=0; i--){
            if(s[i]!=' '){
                temp = s[i] + temp;
            }else if (!temp.empty()) {
                if (!ans.empty()) ans += " ";
                ans += temp;
                temp = "";
            }
        }

        if (!temp.empty()) {
            if (!ans.empty()) ans += " ";
            ans += temp;
        }

        return ans;
    }
};