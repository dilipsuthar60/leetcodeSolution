class Solution {
public:
    int minimumPushes(string s) 
    {
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++) freq[s[i]-'a']++;
        int cost=0;
        sort(freq.rbegin(),freq.rend());
        for(int i=0;i<26;i++){
            if(freq[i]){
                cost+=(i/8+1)*freq[i];
            }
        }
        return cost;
    }
};