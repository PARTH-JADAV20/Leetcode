class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size(), n2 = b.size();
        int total = n1 + n2;

        int mid = total / 2;   

        int i = 0, j = 0, count = 0;
        int prev = 0, curr = 0;

        while (i < n1 || j < n2) {

            prev = curr;

            if (i >= n1) {
                curr = b[j++];
            }
            else if (j >= n2) {
                curr = a[i++];
            }
            else if (a[i] <= b[j]) {
                curr = a[i++];
            }
            else {
                curr = b[j++];
            }

            if (count == mid)
                break;

            count++;
        }

        if (total % 2 == 1)
            return curr;

        return (prev + curr) / 2.0;
    }
};