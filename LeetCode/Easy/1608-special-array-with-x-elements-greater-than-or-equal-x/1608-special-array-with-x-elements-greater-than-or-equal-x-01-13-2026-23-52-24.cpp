class Solution {
public:
    int specialArray(vector<int>& nums) {
        int l = 1, r = nums.size();
        while (l <= r) {
            int mid = (l + r) / 2;
            int cnt = 0;
            for (int num : nums) {
                if (num >= mid) cnt++;
            }

            if (cnt == mid) return mid;

            if (cnt < mid) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};