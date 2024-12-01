class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordCount=1;
        stringstream ss(sentence);
        string currentString="";
        while(ss>>currentString){
            if(currentString.substr(0,searchWord.size())==searchWord){
                return wordCount;
            }
            wordCount++;
        }
        return -1;
    }
};