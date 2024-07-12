class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int index=0;
        for(auto &word:words){
            if(word.front()!=s[index]) return false;
            index++;
        }
        return index==s.size()&&index==words.size();
    }
};