class Solution {
public:
    bool isAnagram(string &s1,string &s2){
        vector<int>frequency(26,0);
        for(auto &ch:s1) frequency[ch-'a']++;
        for(auto &ch:s2) frequency[ch-'a']--;
        for(int i=0;i<26;i++){
            if(frequency[i]!=0) return false;
        }
        return true;
    }
    bool find(string &s,int k){
        int n=s.size();
        string first=s.substr(0,k);
        for(int i=0;i<n;i+=k){
            string current=s.substr(i,k);
            if(!isAnagram(first,current)){
                return false;
            }
        }
        return true;
    }
    int minAnagramLength(string s) {
        int n=s.size();
        int ans=1e8;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(find(s,i)){
                    ans=min(ans,i);
                }
                if(find(s,n/i)){
                    ans=min(ans,n/i);
                }
            }
        }
        return ans;
    }
};