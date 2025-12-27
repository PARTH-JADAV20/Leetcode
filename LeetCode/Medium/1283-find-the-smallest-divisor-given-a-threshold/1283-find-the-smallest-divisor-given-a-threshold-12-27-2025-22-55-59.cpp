class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int i = 1;
        int j = *max_element(nums.begin(),nums.end());

        while(i<j){
            int mid = i + (j - i) / 2;

            long long count = add(nums,mid);

            if(count<=threshold){
                j = mid;
            }else{
                i = mid+1;
            }
        }
        return i;
    }

    long long add(const vector<int>& nums, int m){
        long long count = 0;
        for(int i:nums){
            count += (i + m - 1) / m;
        }
        return count;
    }
};