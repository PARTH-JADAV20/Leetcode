class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++){
            count += negativecount(grid[i], i, m);
        }
        return count;
    }
    
    int negativecount(vector<int>& arr, int row, int m){
        int low = 0, high = m-1;

        while(low<=high){
            int mid = low+(high-low)/2;

            if(arr[mid]<0){
                high = mid-1;
            }else{
                low=mid+1;
            }
        }

        return m-low;
    }
};