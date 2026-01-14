class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n, INT_MAX);
        vector<int> right(n, INT_MAX);
        vector<char> res(dominoes.begin(), dominoes.end());

        int force = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
                force = 0;
            } else if (dominoes[i] == 'L') {
                force = INT_MAX;
            } else {
                force = (force == INT_MAX) ? INT_MAX : force + 1;
            }
            right[i] = force;
        }

        force = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                force = 0;
            } else if (dominoes[i] == 'R') {
                force = INT_MAX;
            } else {
                force = (force == INT_MAX) ? INT_MAX : force + 1;
            }
            left[i] = force;
        }

        for (int i = 0; i < n; i++) {
            if (left[i] < right[i]) {
                res[i] = 'L';
            } else if (right[i] < left[i]) {
                res[i] = 'R';
            }
        }

        return string(res.begin(), res.end());
    }
};