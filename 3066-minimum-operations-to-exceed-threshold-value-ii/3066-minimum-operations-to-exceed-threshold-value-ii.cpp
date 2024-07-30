class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(auto &it:nums) pq.push(it);
        int count=0;
        while(pq.size()>1&&pq.top()<k){
            auto temp1=pq.top();
            pq.pop();
            auto temp2=pq.top();
            pq.pop();
            pq.push(temp1*2+temp2);
            count++;
        }
        return count;
    }
};