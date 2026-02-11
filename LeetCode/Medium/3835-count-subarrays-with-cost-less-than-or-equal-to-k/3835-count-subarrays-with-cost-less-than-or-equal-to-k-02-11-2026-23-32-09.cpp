class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        deque<int> maxD, minD;
        long long ans = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {

            while (!maxD.empty() && nums[maxD.back()] <= nums[r])
                maxD.pop_back();
            maxD.push_back(r);

            while (!minD.empty() && nums[minD.back()] >= nums[r])
                minD.pop_back();
            minD.push_back(r);

            while (!maxD.empty() && !minD.empty() &&
                   (long long)(nums[maxD.front()] - nums[minD.front()]) * (r - l + 1) > k) {

                if (maxD.front() == l) maxD.pop_front();
                if (minD.front() == l) minD.pop_front();
                l++;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};
