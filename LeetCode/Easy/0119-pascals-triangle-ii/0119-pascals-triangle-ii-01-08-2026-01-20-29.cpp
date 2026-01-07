class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;

        for(int i = 0; i <= rowIndex; i++){
            vector<int> temp;
            temp.push_back(1);

            if (i > 0) {
                for (int j = 0; j < ans[i - 1].size() - 1; j++) {
                    temp.push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
                }
                temp.push_back(1);  
            }
            ans.push_back(temp);
        }
        return ans[rowIndex];
    }
};