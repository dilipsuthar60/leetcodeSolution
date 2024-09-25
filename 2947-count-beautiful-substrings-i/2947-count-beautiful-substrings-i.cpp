class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        string vowel = "aeiou";
        int ans=0;
        for(int i=0,n=s.size();i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                if(vowel.find(s[j])!=string::npos){
                    sum++;
                }
                else{
                    sum--;
                }
                if(sum==0){
                    int len=(j-i+1)/2;
                    if((len*len)%(k)==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};