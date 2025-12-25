class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1, ans = INT_MAX;

        while(i<=j){
            int mid = i + (j - i) / 2;
            if(nums[mid] >= nums[i]){
                ans = min(ans, nums[i]);
                i = mid +1;
            }else{
                j = mid - 1;
                ans = min(ans, nums[mid]);
            }
        }

        return ans;
    }
};