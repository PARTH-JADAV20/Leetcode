class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long total = 0;
        for (int num : nums) total += num;
        int remain = total % p;
        if (remain == 0) return 0;

        int res = nums.size();
        long curSum = 0;
        unordered_map<int, int> map;
        map[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            curSum = (curSum + nums[i]) % p;
            int prefix = (curSum - remain + p) % p;
            if (map.count(prefix)) {
                res = min(res, i - map[prefix]);
            }
            map[curSum] = i;
        }

        return res == nums.size() ? -1 : res;
    }
};