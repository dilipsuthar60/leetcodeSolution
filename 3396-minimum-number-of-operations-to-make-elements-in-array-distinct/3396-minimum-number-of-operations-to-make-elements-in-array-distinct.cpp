class Solution {
public:
    bool check(unordered_map<int,int>&mp){
        for(auto &it:mp){
            if(it.second>1){
                return false;
            }
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto &num:nums) mp[num]++;
        if(check(mp)){
            return 0;
        }
        int count=0;
        for(int i=0;i<n;i+=3){
            mp[nums[i]]--;
            if(i+1<n){
                mp[nums[i+1]]--;
            }
            if(i+2<n){
                mp[nums[i+2]]--;
            }
            count++;
            if(check(mp)){
                return count;
            }
        }
        return count;
    }
};