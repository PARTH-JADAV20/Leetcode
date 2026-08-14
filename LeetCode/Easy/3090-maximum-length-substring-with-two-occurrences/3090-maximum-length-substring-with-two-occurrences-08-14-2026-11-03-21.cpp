class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res = 0;
        int fq[26] = {0};

        for (int l = 0, r = 0; r < s.length(); r++) {
            fq[s[r] - 'a']++;;

           while (fq[s[r] - 'a'] > 2) {
            fq[s[l] - 'a']--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};