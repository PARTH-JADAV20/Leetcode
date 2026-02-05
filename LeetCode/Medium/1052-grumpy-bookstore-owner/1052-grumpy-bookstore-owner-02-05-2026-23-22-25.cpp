class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res = 0, n = customers.size();
        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) {
                res += customers[i];
            }
        }
        int curr = 0;
        for(int i = 0; i < minutes; i++) {
            if(grumpy[i] == 1) curr += customers[i];
        }
        int mx = curr;
        for(int i = minutes; i < n; i++) {
            if(grumpy[i - minutes] == 1) curr -= customers[i - minutes];
            if(grumpy[i] == 1) curr += customers[i];
            mx = max(curr, mx);
        }
        return res + mx;
    }
};