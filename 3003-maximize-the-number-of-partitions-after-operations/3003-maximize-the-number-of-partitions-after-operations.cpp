class Solution {
public:
    unordered_map<string,int>dp;
    int find(string &s,int index,int k,int mask,int change){
        if(index==s.size()){
            return 0;
        }
        int newMask= mask|(1<<(s[index]-'a'));
        int countuni=__builtin_popcount(newMask);
        int ans=0;
        string key=to_string(index)+"#"+to_string(mask)+"#"+to_string(change);
        if(dp.find(key)!=dp.end()) return dp[key];
        if(countuni>k)
        {
            ans=max(ans,1+find(s,index+1,k,1<<(s[index]-'a'),change));
        }
        else{
            ans=max(ans,find(s,index+1,k,newMask,change));
        }
        if(change)
        {
            for(int i=0;i<26;i++){
                int newMask= mask|(1<<i);
                int countuni=__builtin_popcount(newMask);
                if(countuni>k){
                     ans=max(ans,1+find(s,index+1,k,(1<<i),0));
                }
                else{
                     ans=max(ans,find(s,index+1,k,newMask,0));
                }
            }
        }
        return dp[key]=ans;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        return find(s,0,k,0,1)+1;
    }
};