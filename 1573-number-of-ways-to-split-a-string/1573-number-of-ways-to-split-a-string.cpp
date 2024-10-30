class Solution {
public:
    const int mod=1e9+7;
    int numWays(string s) {
        int n=s.size();
        int countOne=count(s.begin(),s.end(),'1');
        if(countOne==0){
            return (1ll*(n-1)*(n-2)/2)%mod;
        }
        if(countOne%3!=0) return 0;
        int one=countOne/3;
        long long first=0,second=0;
        int count=0;
        for(int i=0;i<n;i++){
            count+=(s[i]=='1');
            if(count==one) first++;
            else if(count==2*one) second++;
        }
        return (first*second)%mod;
    }
};