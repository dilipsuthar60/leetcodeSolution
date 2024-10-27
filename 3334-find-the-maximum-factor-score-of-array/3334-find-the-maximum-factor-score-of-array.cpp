class Solution {
public:
    long long gcd(long long a,long long b){
        return __gcd(a,b);
    }
    long long lcm(long long a,long long b){
        return a*b/gcd(a,b);
    }
    long long maxScore(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0]*nums[0];
        long long ans=0;
        for(int i=0;i<n;i++){
            long long currGcd=0;
            long long currLcm=0;
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(currGcd==0&&currLcm==0){
                        currLcm=nums[j];
                        currGcd=nums[j];
                    }
                    else{
                        currGcd=gcd(currGcd,nums[j]);
                        currLcm=lcm(currLcm,nums[j]);
                    }
                }
            }
            ans=max(ans,currLcm*currGcd);
        }
        long long currGcd=0;
        long long currLcm=0;
        for(int i=0;i<n;i++){
            if(i==0){
                currGcd=nums[i];
                currLcm=nums[i];
            }
            else{
                currLcm=lcm(currLcm,nums[i]);
                currGcd=gcd(currGcd,nums[i]);
            }
        }
        return max(ans,currLcm*currGcd);
    }
};