class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        int res = 0;
        for (int num : nums) {
            count[num]++;
        }
        for (auto& [num, c] : count) {
            res += c * (c - 1) / 2;
        }
        return res;
    }
};