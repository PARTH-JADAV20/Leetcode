class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string ans = "";
        int len = 0;
        for(int i = n-1; i >= 0; i--){
            if(num[i]%2==0){
                len++;
            }else{
                break;
            }
        }

        return num.substr(0,n-len);
    }
};