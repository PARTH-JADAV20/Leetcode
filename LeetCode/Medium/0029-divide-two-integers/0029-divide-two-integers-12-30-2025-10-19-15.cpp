class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool sign =  true;
        if (dividend >=0 && divisor < 0) sign = false;
        else if (dividend <= 0 && divisor > 0) sign = false;
        long n = labs(dividend);
        long d = labs(divisor);
        long ans = 0;
        while(n >= d){
            int cnt = 0;
            while(n >= (d << (cnt + 1))){
                cnt++;
            }
            ans += 1 << cnt;
            n -= d << cnt;
        }
        if(ans > INT_MAX && sign) 
            return INT_MAX;
        if(ans > INT_MAX && !sign)
            return INT_MIN;

        return sign ? ans : -ans;
    }
};