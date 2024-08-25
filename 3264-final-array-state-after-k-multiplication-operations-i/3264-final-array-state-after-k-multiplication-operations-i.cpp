class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(k--){
            auto temp=pq.top();
            pq.pop();
            pq.push({temp.first*multiplier,temp.second});
        }
        while(pq.size()){
            auto temp=pq.top();
            pq.pop();
            nums[temp.second]=temp.first;
        }
        return nums;
    }
};