class Solution {
public:
    const int MOD = 1337;

    int superPow(int a, vector<int>& b) {
        int res = 1;
        a %= MOD;

        for (int digit : b) {
            res = (powmod(res, 10) * powmod(a, digit)) % MOD;
        }

        return res;
    }

private:
    int powmod(int base, int exp) {
        int result = 1;
        base %= MOD;

        while (exp > 0) {
            if (exp % 2)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }

        return result;
    }
};