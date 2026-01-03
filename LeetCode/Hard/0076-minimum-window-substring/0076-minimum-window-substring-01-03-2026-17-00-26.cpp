class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> freq;
        int n = s.size();
        int m = t.size();

        for(char i : t){
            freq[i]++;
        }

        int minlen = INT_MAX;

        int l = 0,  r = 0;
        int count = 0, sindex = -1;

        while(r<n){
            if(freq[s[r]] > 0) {
                count++;
            }
            freq[s[r]]--;

            while(count == m){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    sindex = l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0){
                    count--;
                }
                l++;
            }

            r++;
        }
        
        return sindex == -1 ? "" : s.substr(sindex,minlen);

    }
};