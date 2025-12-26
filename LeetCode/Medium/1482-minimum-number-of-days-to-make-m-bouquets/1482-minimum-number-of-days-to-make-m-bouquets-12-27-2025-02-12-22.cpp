class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {
        long long total = 1LL * k * m; 

        if (total > arr.size()) return -1;

        int mini = *min_element(arr.begin(), arr.end());
        int maxi = *max_element(arr.begin(), arr.end());

        int low = mini, high = maxi;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (possible(arr, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    bool possible(vector<int>& arr, int day, int m, int k) {
        int n = arr.size();        
        int count = 0;               
        int bouquets = 0;           

        for (int i = 0; i < n; i++) {
            if (arr[i] <= day) {
                count++;
            } else {
                bouquets+=(count/k);
                count = 0;
            }
        }

        bouquets += (count / k);

        return bouquets >= m;
    }
};