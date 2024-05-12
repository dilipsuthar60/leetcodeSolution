class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int>mappingOfwordKlength;
        int sizeOfWord=word.size();
        int maxFreqOfString=0;
        for(int index=0;index<sizeOfWord;index+=k){
            ++mappingOfwordKlength[word.substr(index,k)];
            maxFreqOfString=max(maxFreqOfString,mappingOfwordKlength[word.substr(index,k)]);
        }
        int totalGroupOfKlength=sizeOfWord/k;
        return totalGroupOfKlength-maxFreqOfString;
    }
};