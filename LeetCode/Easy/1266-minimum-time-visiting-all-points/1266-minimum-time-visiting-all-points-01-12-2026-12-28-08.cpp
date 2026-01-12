class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int step = 0;

        for(int i = 0; i < n-1; i++){
            vector<int> prev = points[i];
            vector<int> next = points[i+1];

            int diffx = abs(prev[0]-next[0]);
            int diffy = abs(prev[1]-next[1]);

            int mindis = min(diffx, diffy);

            step += mindis + (diffx-mindis) + (diffy-mindis);
        }
        return step;
    }
};