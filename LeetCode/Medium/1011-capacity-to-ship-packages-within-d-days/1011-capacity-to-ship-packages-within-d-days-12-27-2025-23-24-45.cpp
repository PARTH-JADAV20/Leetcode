class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int i = *max_element(weights.begin(),weights.end());
        int j = accumulate(weights.begin(),weights.end(),0);

        while(i<=j){
            int mid = i + (j - i) / 2;

            int count = finddays(weights,mid);

            if(count<=days){
                j = mid-1;
            }else{
                i = mid+1;
            }
        }
        return i;
    }
    int finddays(const vector<int>& weights, int capacity){
        int days = 1, load = 0;
        for (int w : weights) {
            if (load + w > capacity) {
                days++;
                load = w;
            } else {
                load += w;
            }
        }
        return days;
    }
};