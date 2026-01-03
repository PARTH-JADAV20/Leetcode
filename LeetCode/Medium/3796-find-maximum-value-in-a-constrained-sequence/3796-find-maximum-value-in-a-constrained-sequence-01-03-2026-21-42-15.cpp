class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        const long long INF = 1e18;
        vector<long long> a(n, INF);

        a[0] = 0;

        for (auto &r : restrictions) {
            int idx = r[0];
            int maxVal = r[1];
            a[idx] = min(a[idx], (long long)maxVal);
        }

        for (int i = 0; i < n - 1; i++) {
            a[i + 1] = min(a[i + 1], a[i] + diff[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            a[i] = min(a[i], a[i + 1] + diff[i]);
        }

        long long ans = 0;
        for (long long x : a) {
            ans = max(ans, x);
        }

        return (int)ans;
    }
};