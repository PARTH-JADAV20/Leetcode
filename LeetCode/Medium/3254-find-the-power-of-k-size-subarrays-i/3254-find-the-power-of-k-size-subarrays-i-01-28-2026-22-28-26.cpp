class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        if (k == 1) {
            return nums;
        }

        vector<int> temp;
        for (int i = 0; i < n - 1; i++) {
            temp.push_back(nums[i + 1] - nums[i]);
        }

        int cnt = 0;

        for (int i = 0; i < temp.size(); i++) {

            if (temp[i] == 1) cnt++;

            if (i >= k - 1) {
                if (temp[i - (k - 1)] == 1) cnt--;
            }

            if (i >= k - 2) {
                if (cnt == k - 1) {
                    ans.push_back(nums[i + 1]);
                } else {
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};
