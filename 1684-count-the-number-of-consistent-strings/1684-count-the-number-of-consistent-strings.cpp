class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask=(1<<26)-1;
        for(int i=0;i<allowed.size();i++){
            mask^=(1<<(allowed[i]-'a'));
        }
        int count=0;
        for(int i=0;i<words.size();i++){
            int currentMask=0;
            for(auto &it:words[i]){
                currentMask|=(1<<(it-'a'));
            }
            if((currentMask&mask)==0){
                count++;
            }
        }
        return count;
    }
};