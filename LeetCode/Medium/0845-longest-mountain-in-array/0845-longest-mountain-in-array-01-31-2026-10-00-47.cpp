class Solution {
public:
    int finder(vector<int>& arr, int curr, int n) {
        int i = curr;
        int j = curr;

        while (i > 0 && arr[i] > arr[i - 1]) {
            i--;
        }

        while (j < n - 1 && arr[j] > arr[j + 1]) {
            j++;
        }

        if (i < curr && j > curr) {
            return j - i + 1;  
        }
        return 0;  
    }

    int longestMountain(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();

        for (int i = 1; i < n - 1; i++) {

            if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i]) {
                int temp = finder(arr, i, n);  
                ans = max(ans, temp);  
            }
        }

        return ans;  
    }
};