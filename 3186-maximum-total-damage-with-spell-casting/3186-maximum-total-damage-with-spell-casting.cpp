class Solution {
public:
    long long dp[100004];
    unordered_map<long long,long long>mp;
    vector<long long>nums;
    long long find(int index)
    {
        if(index>=nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        long long notTake=find(index+1);
        long long take=0;
        int nextIndex=index+1;
        while(nextIndex<nums.size()&&nums[nextIndex]-nums[index]<=2){
            nextIndex++;
        }
        take=mp[nums[index]]*nums[index]+find(nextIndex);
        return dp[index]= max(take,notTake);
    }
    long long maximumTotalDamage(vector<int>& power) {
        for(auto &it:power) mp[it]++;
        for(auto &[key,value]:mp) nums.push_back(key);
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        return find(0);
    }
};