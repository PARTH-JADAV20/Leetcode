class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int count = 0;

        for(int i = 0; i<=k; i++){
            if(tickets[i]>tickets[k]){
                count += tickets[k];
            }else{
                count += tickets[i];
            }
        }

        for(int i = k+1; i<n ; i++ ){
            if(tickets[i]>=tickets[k]){
                count += tickets[k] - 1;
            }else{
                count += tickets[i];
            }
        }

        return count;
    }
};