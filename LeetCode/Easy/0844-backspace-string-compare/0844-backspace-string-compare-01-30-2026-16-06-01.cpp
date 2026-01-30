class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a = "";
        string b = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i]=='#' && !a.empty()){
                a.pop_back();
            }else if(s[i]!='#'){
                a.push_back(s[i]);
            }
        }

        for(int i = 0; i < t.size(); i++){
            if(t[i]=='#' && !b.empty()){
                b.pop_back();
            }else if(t[i]!='#'){
                b.push_back(t[i]);
            }
        }
        cout << a << endl;
        cout << b;
        return a == b;
    }
};