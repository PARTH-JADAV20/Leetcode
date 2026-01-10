class Solution {
public:
    string largestGoodInteger(string num) {
        int res = -1;
        for (int i = 0; i < num.length() - 2; ) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                res = max(res, num[i] - '0');
                char c = num[i];
                while (i < num.length() && num[i] == c) i++;
            } else {
                i++;
            }
        }


        return res != -1 ? string(3, res + '0') : "";
    }
};