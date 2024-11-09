class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>&nums, vector<int>& qur)
    {
        map<int,int>mp;
        for(auto&it:nums){
            mp[it[0]]=max(mp[it[0]],it[1]);
        }
        int maxValue=0;
        for(auto &[key,value]:mp){
            maxValue=max(maxValue,value);
            value=maxValue;
        }
        vector<int>ans;
        for(int i=0;i<qur.size();i++){
            auto it=mp.upper_bound(qur[i]);
            if(it==mp.begin()){
                ans.push_back(0);
            }
            else{
                ans.push_back((*prev(it)).second);
            }
        }
        return ans;
    }
};