class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            unordered_map<char,int> freq;

            for(int j = i; j < n; j++) {
                freq[s[j]]++;
                int count = -1;
                bool isBalanced = true;

                for(auto &p : freq) {
                    if(count == -1) {
                        count = p.second;
                    } 
                    else if(p.second != count) {
                        isBalanced = false;
                        break;
                    }
                }

                if(isBalanced) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
