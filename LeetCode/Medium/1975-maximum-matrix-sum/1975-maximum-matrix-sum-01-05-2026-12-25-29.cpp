class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxneg = INT_MAX;
        int negcnt = 0;
        long long sum = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                maxneg = min(maxneg, abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    negcnt++;
                    sum+=(-1*matrix[i][j]);
                }else{
                    sum+=matrix[i][j];
                }
            }
        }

        cout << sum << endl;

        cout << maxneg;

        long long ans = negcnt % 2 == 0 ? sum : sum - (2*maxneg);
        return ans;
    }
};