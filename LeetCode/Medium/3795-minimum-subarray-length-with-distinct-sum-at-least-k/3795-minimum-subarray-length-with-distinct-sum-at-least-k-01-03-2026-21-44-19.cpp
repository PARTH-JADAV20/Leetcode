class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int minlen = INT_MAX;
        map<int, int> freq;

        while(r<n){
            if(freq[nums[r]]==0){
                sum+=nums[r];
            }
            freq[nums[r]]++;
            while(sum>=k){
                minlen = min(minlen, r-l+1);
                freq[nums[l]]--;
                if(freq[nums[l]]==0){
                    sum-=nums[l];
                }
                l++;
            }
            r++;
        }

        return minlen == INT_MAX? -1 : minlen;
    }
};