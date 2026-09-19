class WordDictionary {
public:
    set<string> dict;

    WordDictionary() {
    }
    
    void addWord(string word) {
        this->dict.insert(word);
    }

    bool normal(string word) {
        return dict.find(word) != dict.end();
    }
    
    bool search(string word) {
        bool flag = false;

        for (char c : word) {
            if (c == '.') {
                flag = true;
            }
        }

        if (!flag) {
            return normal(word);
        }

        for (const string& w : this->dict) {

            if (w.size() != word.size()) {
                continue;
            }

            bool match = true;

            for (int i = 0; i < word.size(); i++) {

                if (word[i] == '.') {
                    continue;
                }

                if (word[i] != w[i]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                return true;
            }
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */