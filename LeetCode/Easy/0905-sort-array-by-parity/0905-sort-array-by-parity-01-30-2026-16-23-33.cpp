class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int a = 0;
        int b = n - 1;

        while (a < b) {
            while (a < b && nums[a] % 2 == 0) {
                a++;
            }
            while (a < b && nums[b] % 2 != 0) {
                b--;
            }
            if (a < b) {
                swap(nums[a], nums[b]);
            }
        }

        return nums;
    }
};
