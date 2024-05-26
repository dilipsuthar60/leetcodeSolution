class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int n=word.size();
        for(int i=0,j=0;i<n;i=j){
            int count=0;
            while(i<n&&word[i]==word[j]&&count<9)
            {
                count++;
                j++;
            }
            ans+=to_string(count)+word[i];
        }
        return ans;
    }
};