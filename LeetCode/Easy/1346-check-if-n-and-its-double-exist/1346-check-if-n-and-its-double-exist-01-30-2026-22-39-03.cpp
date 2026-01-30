class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();

        map<int , int> temp;

        for(int i = 0; i < arr.size(); i++){
            if (temp.count(2 * arr[i])) return true;

            if (arr[i] % 2 == 0 && temp.count(arr[i] / 2)) return true;

            temp[arr[i]]++;
        }

        return false;
    }
};