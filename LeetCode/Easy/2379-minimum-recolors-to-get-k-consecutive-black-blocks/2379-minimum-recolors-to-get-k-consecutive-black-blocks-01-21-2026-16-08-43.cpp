class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int bcount = 0;

        for(int i = 0; i < k; i++){
            if (blocks[i]=='B') bcount++;
        }

         int maxB = bcount;

        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i - k] == 'B') bcount--;   
            if (blocks[i] == 'B') bcount++;      
            maxB = max(maxB, bcount);
        }

        return k - maxB;
    }
};