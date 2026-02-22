class Solution {
public:
    int binaryGap(int n) {
        int last = -1;
        int maxGap = 0;
        int position = 0;

        while (n > 0) {
            if (n & 1) {
                if (last != -1) {
                    maxGap = max(maxGap, position - last);
                }
                last = position;
            }
            n >>= 1;
            position++;
        }

        return maxGap;
    }
};
