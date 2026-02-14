#include <string>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1; 
        int n = preorder.size();

        for (int i = 0; i < n; ) {
            if (slots == 0) return false;  

            if (preorder[i] == '#') {
                slots--;   
                i++;
            } else {
                while (i < n && preorder[i] != ',') i++;
                slots--;   
                slots += 2; 
            }

            if (i < n && preorder[i] == ',') i++; 
        }

        return slots == 0;
    }
};
