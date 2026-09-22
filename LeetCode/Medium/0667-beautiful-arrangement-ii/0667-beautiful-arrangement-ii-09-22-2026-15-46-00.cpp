class Solution {
public:
    vector<int> constructArray(int n, int k) {

        vector<int> answer;

        int low = 1;
        int high = k + 1;

        while (low <= high) {

            answer.push_back(low);

            if (low != high) {
                answer.push_back(high);
            }

            low++;
            high--;
        }

        // Add remaining numbers
        for (int i = k + 2; i <= n; i++) {
            answer.push_back(i);
        }

        return answer;
    }
};