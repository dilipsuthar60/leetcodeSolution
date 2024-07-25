class Solution {
public:
    long long dp[105][105][105];
    const int mod=1e9+7;
    long long power(long long a,long long b){
        long long res=1;
        while(b){
            if(b&1){
                res*=a;
                res%=mod;
            }
            a=(a*a)%mod;
            b/=2;
        }
        return res%mod;
    }
    long long find(vector<int>&nums,int index,int sum,int len,int k){
        if(sum==k) return power(2,(int)nums.size()-len);
        if(index>=nums.size()||sum>k) return 0;
        if(dp[index][sum][len]!=-1) return dp[index][sum][len]%mod;
        long long take=find(nums,index+1,sum+nums[index],len+1,k);
        long long notTake=find(nums,index+1,sum,len,k);
        return dp[index][sum][len] = (take+notTake)%mod;
    }
    int sumOfPower(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return find(nums,0,0,0,k)%mod;
    }
};