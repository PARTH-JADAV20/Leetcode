class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<vector<string>> ans;
        // vector<int> indx;

        // for (int i = 0; i < strs.size(); i++) {
        //     if (find(indx.begin(), indx.end(), i) != indx.end())
        //         continue;
        //     vector<string> temp;
        //     temp.push_back(strs[i]);
        //     indx.push_back(i);

        //     string a = strs[i];
        //     sort(a.begin(), a.end());

        //     for (int j = i + 1; j < strs.size(); j++) {
        //         string b = strs[j];
        //         sort(b.begin(), b.end());

        //         if (a == b && find(indx.begin(), indx.end(), j) == indx.end()) {
        //             indx.push_back(j);
        //             temp.push_back(strs[j]);
        //         }
        //     }
        //     ans.push_back(temp);
        // }

        // return ans;


        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string key = s;         // copy
            sort(key.begin(), key.end());  // sort to form key
            mp[key].push_back(s);   // group by sorted key
        }
        vector<vector<string>> ans;
        for (auto &entry : mp)
            ans.push_back(entry.second);

        return ans;
    }
};