class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans=0;
        int freq[26];
        memset(freq,0,sizeof(freq));
        for(int i=0,n=s.size(),j=0;i<n;i++){
            freq[s[i]-'a']++;
            while(j<=i&&freq[s[i]-'a']>=k){
                ans+=n-i;
                freq[s[j]-'a']--;
                j++;
            }
        }
        return ans;
    }
};