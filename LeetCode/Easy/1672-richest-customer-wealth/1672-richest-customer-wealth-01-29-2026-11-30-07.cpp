class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int count = 0;
        int maxwealth = 0;

        for(vector<int> nums : accounts){
            int sum = accumulate(nums.begin(), nums.end(), 0);
            maxwealth = max(maxwealth, sum);
        }

        return maxwealth;
    }
};