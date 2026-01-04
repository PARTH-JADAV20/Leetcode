class Solution {
public:
    bool isPerfectSquare(int num) {

        if (num == 0 || num == 1)
            return num;

        long long low = 1, high = num;
        int ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid * mid == num)
                return true;

            if (mid * mid < num) {
                ans = mid;     
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
        
    }
};