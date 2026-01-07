class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> numfreq;
        int num = -1;

        for(int i : arr){
            numfreq[i]++;
        }

        for(auto& i : numfreq){
            if(i.first == i.second){
                num = i.first;
            }
        }

        return num;
    }
};