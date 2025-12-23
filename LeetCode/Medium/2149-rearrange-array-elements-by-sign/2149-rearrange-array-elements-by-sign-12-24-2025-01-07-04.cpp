class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos ;
        vector<int> neg ;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }else{
                neg.push_back(nums[i]);
            }
        }

        int p = 0, q = 0;

        for (int i = 0; i < n; i += 2) {
            nums[i] = pos[p++];
            nums[i + 1] = neg[q++];
        }

        return nums;
    }
};