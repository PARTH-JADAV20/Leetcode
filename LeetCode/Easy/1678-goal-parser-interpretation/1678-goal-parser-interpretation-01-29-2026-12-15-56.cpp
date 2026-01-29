class Solution {
public:
    string interpret(string command) {
        int n = command.size();
        string ans = "";
        for(int i = 0; i < n ; i++){
            if(command[i] == 'G'){
                ans+='G';
            }else if(i<n-1 && command[i] == '(' && command[i+1] == ')'){
                ans+='o';
            }else if( i<n-1 && command[i] == '(' && command[i+1] == 'a'){
                ans+="al";
            }
        }
        return ans;
    }
};