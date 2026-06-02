class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        int count=1;
        vector<int>merged;
        sort(points.begin(),points.end());
        vector<int>prev=points[0];

        for(int i=1;i<points.size();i++){
        if(prev[1]>=points[i][0]){
                prev[1]=min(points[i][1],prev[1]);
            } else{ 
                count++;
                prev=points[i];
            }
        }


        return count;
    }
};