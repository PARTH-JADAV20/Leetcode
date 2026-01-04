class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int num : nums) {
            int count = 0;
            int sum = 0;

            for (int d = 1; d * d <= num; d++) {
                if (num % d == 0) {
                    int d1 = d;
                    int d2 = num / d;

                    if (d1 == d2) {
                       // perfect square → cannot have exactly 4 divisors
                        count = 5;   // force invalid
                        break;
                    } else {
                        count += 2;
                        sum += d1 + d2;
                    }

                    if (count > 4) break;
                }
            }

            if (count == 4) {
                ans += sum;
            }
        }

        return ans;
    }
};