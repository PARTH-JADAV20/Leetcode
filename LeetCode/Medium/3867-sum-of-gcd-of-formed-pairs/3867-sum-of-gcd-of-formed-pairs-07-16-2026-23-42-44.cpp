class Solution {
public:
    long long gcdSum(vector<int>& A) {
        int maxe = 0;

        for (auto& n : A) {
            maxe = max(maxe, n);
            n = gcd(n, maxe);
        }

        sort(A.begin(),A.end());

        long long res = 0;
        for (int i = 0, j = A.size() - 1; i < j; i++, j--)
            res += gcd(A[i], A[j]);

        return res;
    }
};