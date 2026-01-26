class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int mn = INT_MAX;

        for (int i = 0; i + 1 < arr.size(); i++) {
            int diff = arr[i + 1] - arr[i];
            if (diff < mn) {
                mn = diff;
                res.clear();
            }
            if (diff == mn) {
                res.push_back({arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};