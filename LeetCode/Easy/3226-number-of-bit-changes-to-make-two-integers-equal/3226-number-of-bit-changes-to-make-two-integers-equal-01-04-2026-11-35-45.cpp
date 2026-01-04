class Solution {
public:
    int minChanges(int n, int k) {
        if ((k & ~n) != 0)
            return -1;

        int x = n & ~k; 
        int count = 0;

        while (x > 0) {
            x = x & (x - 1);
            count++;
        }

        return count;
        
    }
};