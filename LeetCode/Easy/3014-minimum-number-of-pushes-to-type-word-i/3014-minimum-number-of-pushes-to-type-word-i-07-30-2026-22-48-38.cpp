class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int count = 0;
        int ans = 0;
        if(n<=8){
            return n;
        }
        for(int i = 0; n > 8; i++){
            count++;
            n=n-8;
        }
        for(int i = 1; i<=count; i++){
            ans = ans + (i * 8);
        }

        ans = ans + ((count+1) * n);

        return ans;

    }
};