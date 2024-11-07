class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size();
        vector<int>freq(4,0);
        
        for(auto &it:s) freq[it-'a']++;
        
        if(freq[0]<k||freq[1]<k||freq[2]<k) 
            return -1;
        int window=0;
        int j=0;
        int ans=1e9;
        for(int i=0;i<n;i++){
            freq[s[i]-'a']--;
            window++;
            while(freq[s[i]-'a']<k){
                freq[s[j]-'a']++;
                j++;
                window--;
            }
            ans=min(ans,n-window);
        }
        return ans;
    }
};