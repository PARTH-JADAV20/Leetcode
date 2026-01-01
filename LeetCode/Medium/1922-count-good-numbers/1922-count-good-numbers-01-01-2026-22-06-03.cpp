class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long fastPow(long long base, long long exp) {
        long long result = 1;

        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % MOD;

            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;

        long long ans =
            (fastPow(5, evenCount) * fastPow(4, oddCount)) % MOD;

        return ans;
    }
};
