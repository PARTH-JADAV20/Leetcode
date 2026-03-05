class Solution {
public:
    int reachNumber(int target)
    {
        int sum=0;
        int moves=0;

        target=abs(target);

        while(true)
        {
            moves++;
            sum=sum+moves;
            if((sum>=target) && ((sum-target)%2==0))
                return moves;
        }
        return -1;
    }
};