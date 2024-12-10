class Solution {
public:
    bool find(string &s,int k){
        for(char ch='a';ch<='z';ch++){
            int count=0;
            int total=0;
            for(int i=0;i<s.size();i++){
                if(s[i]==ch){
                    count++;
                }
                else{
                    count=0;
                }
                total+=(count>=k);
                if(total>=3){
                    return true;
                }
            }
        }
        return false;
    }
    int maximumLength(string s) {
        int n=s.size();
        int ans=-1;
        for(int len=1;len<=n;len++){
            if(find(s,len)){
                ans=max(ans,len);
            }
        }
        return ans;
    }
};