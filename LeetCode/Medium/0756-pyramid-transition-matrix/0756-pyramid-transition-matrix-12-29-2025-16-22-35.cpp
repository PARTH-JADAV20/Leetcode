class Solution {
public:
    map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        mp.clear();
        memo.clear();

        for (string s : allowed) {
            mp[s.substr(0,2)].push_back(s[2]);
        }

        return canBuild(bottom);
    }

    bool canBuild(string row) {
        if (row.length() == 1)
            return true;

        if (memo.count(row))
            return memo[row];

        vector<string> nextRows;
        generateNextRows(row, 0, "", nextRows);

        for (string next : nextRows) {
            if (canBuild(next))
                return memo[row] = true;
        }

        return memo[row] = false;
    }

    void generateNextRows(string &row, int index, string current,
                          vector<string> &nextRows) {
        if (index == row.length() - 1) {
            nextRows.push_back(current);
            return;
        }

        string key = row.substr(index, 2);
        if (!mp.count(key)) return;

        for (char ch : mp[key]) {
            generateNextRows(row, index + 1, current + ch, nextRows);
        }
    }
};
