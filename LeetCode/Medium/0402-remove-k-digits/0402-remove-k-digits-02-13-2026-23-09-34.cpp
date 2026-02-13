class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st;  // acts like a stack

        for (char digit : num) {
            // Remove larger digits from stack
            while (k > 0 && !st.empty() && st.back() > digit) {
                st.pop_back();
                k--;
            }
            st.push_back(digit);
        }

        // If still digits need to remove, remove from end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Build result string
        string result(st.begin(), st.end());

        // Remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }
        result = result.substr(i);

        return result.empty() ? "0" : result;
    }
};