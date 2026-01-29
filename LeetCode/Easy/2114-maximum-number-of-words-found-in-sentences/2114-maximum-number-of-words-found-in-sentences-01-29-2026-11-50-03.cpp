class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxwords = 0;
        for(string str : sentences){
            int count = 0;
            for(char s : str){
                maxwords = max(maxwords, count);
                if(s==' '){
                    count ++;
                }
            }
            maxwords = max(maxwords , count+1);
        }
        return maxwords;
    }
};