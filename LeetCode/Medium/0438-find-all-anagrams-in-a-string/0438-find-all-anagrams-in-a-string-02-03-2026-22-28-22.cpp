#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        if (p.length() > s.length())
            return result;

        unordered_map<char, int> pCount, windowCount;

        for (char c : p) {
            pCount[c]++;
        }

        int windowSize = p.length();

        for (int i = 0; i < windowSize; i++) {
            windowCount[s[i]]++;
        }

        if (windowCount == pCount) {
            result.push_back(0);
        }

        for (int i = windowSize; i < s.length(); i++) {
            windowCount[s[i]]++;

            char leftChar = s[i - windowSize];
            windowCount[leftChar]--;
            if (windowCount[leftChar] == 0) {
                windowCount.erase(leftChar);
            }

            if (windowCount == pCount) {
                result.push_back(i - windowSize + 1);
            }
        }

        return result;
    }
};
