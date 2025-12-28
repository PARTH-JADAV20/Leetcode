class Solution {
public:
    string frequencySort(string s) {
        map<char , int> freq;

        for(char i : s){
            freq[i]++;
        }

        multimap<int,char> mm;

        for (auto &p : freq) {
            mm.insert({p.second, p.first});
        }

        string ans = "";
        for (auto it = mm.rbegin(); it != mm.rend(); it++) {
            ans.append(it->first, it->second);
        }

        return ans;
    }
};