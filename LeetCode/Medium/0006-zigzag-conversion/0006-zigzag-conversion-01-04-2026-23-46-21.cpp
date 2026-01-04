class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows)
            return s;

        vector<string> rows(numRows);
        int cycleLen = 2 * (numRows - 1);

        for (int i = 0; i < s.length(); i++) {
            int pos = i % cycleLen;
            int row = (pos < numRows) ? pos : cycleLen - pos;
            rows[row] += s[i];
        }

        string ans = "";
        for (string &row : rows)
            ans += row;

        return ans;
    }
};