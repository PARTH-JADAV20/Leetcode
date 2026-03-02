class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int n = nums.size();
        unordered_map<int,int> freq;
        
        long long ans = 0;
        int left = 0;
        int validLeft = 0;
        int distinct = 0;
        int good = 0;
        
        for (int right = 0; right < n; right++) {
            
            if (freq[nums[right]] == 0)
                distinct++;
            
            freq[nums[right]]++;
            
            if (freq[nums[right]] == m)
                good++;
            
            while (distinct > k) {
                if (freq[nums[left]] == m)
                    good--;
                
                freq[nums[left]]--;
                
                if (freq[nums[left]] == 0)
                    distinct--;
                
                left++;
                
                validLeft = left;
            }
            
            while (distinct == k && good == k) {
                
                if (freq[nums[validLeft]] == m)
                    break;
                
                freq[nums[validLeft]]--;
                validLeft++;
            }
            
            if (distinct == k && good == k)
                ans += (validLeft - left + 1);
        }
        
        return ans;
    }
};