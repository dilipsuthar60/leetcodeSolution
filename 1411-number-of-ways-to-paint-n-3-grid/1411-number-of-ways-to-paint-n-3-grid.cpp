class Solution {
public:
    const int mod=1e9+7;
    long long cache[5005][4][4][4];
    void getAllCombination(vector<int>&nums,int index,vector<int>&curr,vector<vector<int>>&result){
        if(index>=3){
            result.push_back(curr);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(curr.size()==0||(curr.back()!=nums[i])){
                curr.push_back(nums[i]);
                getAllCombination(nums,index+1,curr,result);
                curr.pop_back();
                
            }
        }
    }
    long long find(vector<vector<int>>&nums,int index,int a,int b,int c,int n){
        if(index==n) return 1;
        long long ans=0;
        if(cache[index][a][b][c]!=-1) return cache[index][a][b][c]%mod;
        for(auto &color:nums){
            if(color[0]!=a&&color[1]!=b&&color[2]!=c){
                ans+=find(nums,index+1,color[0],color[1],color[2],n);
            }
        }
        return cache[index][a][b][c] = ans%mod;
    }
    int numOfWays(int n) {
        memset(cache,-1,sizeof(cache));
        vector<int>curr;
        vector<vector<int>>result;
        vector<int>nums={1,2,3};
        getAllCombination(nums,0,curr,result);
        return find(result,0,0,0,0,n);
    }
};