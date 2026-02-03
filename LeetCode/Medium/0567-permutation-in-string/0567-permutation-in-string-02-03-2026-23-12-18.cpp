#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        int s1Count[26] = {0};
        int windowCount[26] = {0};

        for (char c : s1) {
            s1Count[c - 'a']++;
        }

        int windowSize = s1.length();

        for (int i = 0; i < windowSize; i++) {
            windowCount[s2[i] - 'a']++;
        }

        if (isEqual(s1Count, windowCount))
            return true;

        for (int i = windowSize; i < s2.length(); i++) {
            windowCount[s2[i] - 'a']++;

            windowCount[s2[i - windowSize] - 'a']--;

            if (isEqual(s1Count, windowCount))
                return true;
        }

        return false;
    }

private:
    bool isEqual(int a[], int b[]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
};
