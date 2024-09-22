class Solution {
public:
    bool check(vector<int>&count1,vector<int>&count2){
        for(int i=0;i<26;i++){
            if(count1[i]>count2[i]) return false;
        }
        return true;
    }
    long long validSubstringCount(string word1, string word2) {
        int n=word1.size();
        vector<int>count1(26,0);
        vector<int>count2(26,0);
        for(int i=0;i<word2.size();i++){
            count1[word2[i]-'a']++;
        }
        long long count=0;
        for(int i=0,j=0;i<n;i++){
            count2[word1[i]-'a']++;
            while(check(count1,count2)){
                count+=n-i;
                count2[word1[j]-'a']--;
                j++;
            }
        }
        return count;
    }
};