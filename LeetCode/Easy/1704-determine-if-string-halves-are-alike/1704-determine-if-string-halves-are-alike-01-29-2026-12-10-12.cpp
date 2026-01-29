class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int count1 = 0;
        int count2 = 0;

        for(int i=0 ; i<n; i++){
            if(i<n/2 && (s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')){
                count1++;
            }else if(i>=n/2 && (s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')){
                count2++;
            }
        }
        return count1==count2;
    }
};