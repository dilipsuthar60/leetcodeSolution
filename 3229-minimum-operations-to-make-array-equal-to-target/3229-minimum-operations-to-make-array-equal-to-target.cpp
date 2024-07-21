class Solution {
public:
    long long find(vector<int>&nums){
        for(auto &it:nums){
            it=abs(it);
        }
        long long count=nums.front();
        for(int i=1,n=nums.size();i<n;i++){
            count+=max(nums[i]-nums[i-1],0);
        }
        return count;
    }
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        vector<int>diff;
        for(int i=0;i<n;i++){
            diff.push_back(target[i]-nums[i]);
        }
        stack<pair<int,vector<int>>>s;
        for(int i=0;i<n;i++){
            if(s.size()>0&&s.top().first<0&&diff[i]<0){
                s.top().second.push_back(diff[i]);
            }
            else if(s.size()&&s.top().first>0&&diff[i]>0){
                s.top().second.push_back(diff[i]);
            }
            else{
                s.push({diff[i]>0?1:-1,{diff[i]}});
            }
        }
        long long operation=0;
        while(s.size()){
            auto it=s.top();s.pop();
            operation+=find(it.second);
        }
        return operation;
    }
};