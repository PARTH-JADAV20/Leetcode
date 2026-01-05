class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int studentIndex = 0;
        int cookieIndex = 0;

        while (studentIndex < g.size() && cookieIndex < s.size()) {
            if (s[cookieIndex] >= g[studentIndex]) {
                studentIndex++;
            }
            cookieIndex++;
        }
        return studentIndex;
    }
};