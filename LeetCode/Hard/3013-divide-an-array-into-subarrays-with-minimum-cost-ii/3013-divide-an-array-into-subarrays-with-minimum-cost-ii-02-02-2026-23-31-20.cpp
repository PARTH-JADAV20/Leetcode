class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        auto cmp = [&](int a, int b) {
            if (nums[a] == nums[b]) return a < b;
            return nums[a] < nums[b];
        };

        set<int, decltype(cmp)> sel(cmp), rem(cmp);

        k = k - 1;

        long long currSum = 0;
        long long ans = LLONG_MAX;

        int last = min(dist + 1, n - 1);
        for (int i = 1; i <= last; i++) {
            currSum += nums[i];
            sel.insert(i);
        }

        while ((int)sel.size() > k) {
            auto it = prev(sel.end());
            currSum -= nums[*it];
            rem.insert(*it);
            sel.erase(it);
        }

        ans = currSum;

        for (int r = dist + 2, l = 1; r < n; r++, l++) {
            rem.insert(r);

            if (sel.count(l)) {
                sel.erase(l);
                currSum -= nums[l];

                int smallest = *rem.begin();
                rem.erase(rem.begin());
                sel.insert(smallest);
                currSum += nums[smallest];
            } else {
                rem.erase(l);

                if (!sel.empty() && !rem.empty() &&
                    nums[*prev(sel.end())] > nums[*rem.begin()]) {

                    int big = *prev(sel.end());
                    sel.erase(prev(sel.end()));
                    currSum -= nums[big];
                    rem.insert(big);

                    int small = *rem.begin();
                    rem.erase(rem.begin());
                    sel.insert(small);
                    currSum += nums[small];
                }
            }

            ans = min(ans, currSum);
        }

        return nums[0] + ans;
    }
};