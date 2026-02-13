class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string curr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                // Build number (could be more than 1 digit)
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                // Push current number and string
                countStack.push(num);
                stringStack.push(curr);

                // Reset
                num = 0;
                curr = "";
            }
            else if (c == ']') {
                int repeat = countStack.top();
                countStack.pop();

                string prev = stringStack.top();
                stringStack.pop();

                // Repeat current string
                for (int i = 0; i < repeat; i++) {
                    prev += curr;
                }

                curr = prev;
            }
            else {
                // Normal character
                curr += c;
            }
        }

        return curr;
    }
};