#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char c : expression) {
            if (c == ',' ) continue;  // Ignore commas
            
            if (c != ')') {
                st.push(c);
            } 
            else {
                // Evaluate expression inside parentheses
                int trueCount = 0, falseCount = 0;

                while (st.top() != '(') {
                    char val = st.top();
                    st.pop();
                    if (val == 't') trueCount++;
                    else if (val == 'f') falseCount++;
                }

                st.pop(); // remove '('
                char op = st.top(); 
                st.pop(); // remove operator

                if (op == '!') {
                    st.push(falseCount == 1 ? 't' : 'f');
                }
                else if (op == '&') {
                    st.push(falseCount == 0 ? 't' : 'f');
                }
                else if (op == '|') {
                    st.push(trueCount > 0 ? 't' : 'f');
                }
            }
        }

        return st.top() == 't';
    }
};
