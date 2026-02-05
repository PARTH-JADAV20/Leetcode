class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int maxSum=nums[0];
       int minSum=nums[0];
       int maxres=nums[0];
       int minres=nums[0];
       int totalsum=0;
       for(int i:nums){
        totalsum+=i;
       } 
       for(int i=1;i<nums.size();i++){
        maxSum=max(maxSum+nums[i],nums[i]);
        minSum=min(minSum+nums[i],nums[i]);
        maxres=max(maxres,maxSum);
        minres=min(minres,minSum);
       }
       int res =max(maxres,(totalsum-minres));
       if(totalsum==minres) return maxres;
       else return res;

    }
};