class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magcount;
        for (char c : magazine) {
            magcount[c]++;
        }
        unordered_map<char, int> rancount;
        for (char c : ransomNote) {
            rancount[c]++;
        }
        int ans = true;
        for (const auto& p : rancount) {
            if (p.second > magcount[p.first]) {
                ans = false;
                break;
            }
        }

        return ans;
    }
};