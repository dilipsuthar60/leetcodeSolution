class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int count=0;
        for(int i=0,n=word.size();i<n-1;i++){
            if(abs(word[i]-word[i+1])<=1){
                count++;
                i++;
            }
        }
        return count;
    }
};