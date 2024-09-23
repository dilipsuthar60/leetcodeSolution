class Solution {
public:
    long long minNumberOfSeconds(int height, vector<int>& worker) {
        priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>>pq;
        for(int i=0;i<worker.size();i++){
            pq.push({worker[i],1,i});
        }
        long long ans=0;
        while(height--){
            auto [cost,currentValue,index]=pq.top();
            pq.pop();
            ans=max(ans,cost);
            pq.push({cost+1ll*worker[index]*(currentValue+1),currentValue+1,index});
        }
        return ans;
    }
};