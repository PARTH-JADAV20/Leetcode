class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxCount = 0;
        int n = s.size();

        for(int i = 0; i<n; i++){
            if(s[i]=='('){
                count++;
            }
            maxCount = max(count, maxCount);
            if(s[i]==')'){
                count--;
            }
        }

        return maxCount;
    }
};