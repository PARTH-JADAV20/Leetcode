class Solution {
public:
    int dominantIndex(vector<int>& arr) {
        int n = arr.size();

    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    int ans = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            ans = i;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if(largest >= 2*secondLargest){
        return ans;
    }else{
        return -1;
    }

    }
};