class Solution {
public:
    unordered_map<int,unordered_map<int,int>>mp[11];
    int mx=(1<<19)-1;
    int find(vector<int>&nums,vector<int>&value,int index,int j,int currentAnd){
        if(index>=nums.size()&&j>=value.size()) return 0;
        if(index>=nums.size()||j>=value.size()) return 1e9;
        if(mp[j][currentAnd].find(index)!=mp[j][currentAnd].end()) return mp[j][currentAnd][index];
        int option1=find(nums,value,index+1,j,currentAnd&nums[index]);
        int option2=1e8;
        if((currentAnd&nums[index])==value[j]){
            option2 = nums[index]+find(nums,value,index+1,j+1,mx);
        }
        return mp[j][currentAnd][index] = min(option1,option2);
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int ans=find(nums,andValues,0,0,mx);
        if(ans>=1e7) return -1;
        return ans;
    }
};