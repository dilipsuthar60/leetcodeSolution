class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int limit=sqrt(r);
        vector<bool>prime(limit+1,true);
        prime[0]=prime[1]=false;
        for(int i=2;i<=limit;i++){
            if(prime[i]){
                for(int j=2*i;j<=limit;j+=i){
                    prime[j]=false;
                }
            }
        }
        int count=0;
        for(int i=1;i<=limit;i++){
            if(prime[i]){
                int squre=i*i;
                if(l<=squre&&squre<=r){
                    count++;
                }
            }
        }
        return (r-l+1)-count;
    }
};