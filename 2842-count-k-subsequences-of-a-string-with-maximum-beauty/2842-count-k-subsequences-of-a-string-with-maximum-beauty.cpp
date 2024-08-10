class Solution {
public:
    const int mod=1e9+7;
    int n;
    int requiredLength=0;
    int memo[26][26];
    long long find(vector<int>&nums,int index,int k){
        if(index>=nums.size()){
            return k==requiredLength;
        }
        if(memo[index][k]!=-1) return memo[index][k]%mod;
        long long notTake=find(nums,index+1,k);
        long long take=0;
        if(nums[index]==nums[k]){
            take=nums[index]*find(nums,index+1,k+1);
        }
        return memo[index][k] =  (take+notTake)%mod;
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        memset(memo,-1,sizeof(memo));
        this->n=s.size();
        this->requiredLength=k;
        int map[26]={0};
        for(auto &it:s) map[it-'a']++;
        vector<int>higestFreq;
        for(int i=0;i<26;i++){
            if(map[i]) higestFreq.push_back(map[i]);
        }
        if(higestFreq.size()<k) return 0;
        sort(higestFreq.rbegin(),higestFreq.rend());
        return find(higestFreq,0,0);
    }
};