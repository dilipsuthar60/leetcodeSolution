class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>present,unique;
        vector<int>ans;
        for(auto &it:queries){
            int ball=it[0];
            int color=it[1];
            if(present.find(ball)!=present.end()){
                if(--unique[present[ball]]==0){
                    unique.erase(present[ball]);
                }
            }
            present[ball]=color;
            unique[color]++;
            ans.push_back(unique.size());
        }
        return ans;
    }
};