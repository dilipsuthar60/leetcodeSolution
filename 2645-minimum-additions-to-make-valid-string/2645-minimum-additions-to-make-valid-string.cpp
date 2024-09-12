class Solution {
public:
    int addMinimum(string s) {
        int ans=0;
        
        for(int i=0,n=s.size();i<n;){
            int count=0;
            if(s[i]=='a'){
                count++;
                i++;
            }
            if(i<n&&s[i]=='b'){
                count++;
                i++;
            }
            if(i<n&&s[i]=='c'){
                count++;
                i++;
            }
            ans+=(3-count);
        }
        return ans;
    }
};