class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int>pq;
        int size=queries.size();
        vector<int>ans(size,-1);
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int y=queries[i][1];
            pq.push(abs(x)+abs(y));
            if(pq.size()>k){
                auto top=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans[i]=pq.top();
            }
        }
        return ans;
    }
};