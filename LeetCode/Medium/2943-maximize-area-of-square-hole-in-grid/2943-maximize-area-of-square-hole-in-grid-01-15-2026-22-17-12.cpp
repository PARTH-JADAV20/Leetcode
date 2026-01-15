class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int cntH = 1, cntV = 1;
        int maxH = 1, maxV = 1;

        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] - hBars[i - 1] == 1) {
                cntH++;
            } else {
                maxH = max(maxH, cntH);
                cntH = 1;
            }
        }

        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] - vBars[i - 1] == 1) {
                cntV++;
            } else {
                maxV = max(maxV, cntV);
                cntV = 1;
            }
        }

        maxH = max(maxH, cntH);
        maxV = max(maxV, cntV);

        int side = min(maxH + 1, maxV + 1);
        return side * side;
    }
};