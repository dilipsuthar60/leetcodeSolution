class Solution {
public:
    long long minNumberOfSeconds(int height, vector<int>& worker) {
        set<tuple<long long,int,int>>s;
        for(int i=0;i<worker.size();i++){
            s.insert({worker[i],1,i});
        }
        long long ans=0;
        while(height--){
            auto [cost,currentValue,index]=*s.begin();
            s.erase(s.begin());
            ans=max(ans,cost);
            s.insert({cost+1ll*worker[index]*(currentValue+1),currentValue+1,index});
        }
        return ans;
    }
};