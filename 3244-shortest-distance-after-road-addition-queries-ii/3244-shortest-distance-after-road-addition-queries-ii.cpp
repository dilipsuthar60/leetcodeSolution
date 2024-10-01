class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(i);
        }
        vector<int>result;
        for(auto &query:queries){
            int x=query[0];
            int y=query[1];
            auto lower =s.lower_bound(x+1);
            auto upper =s.upper_bound(y-1);
            s.erase(lower,upper);
            result.push_back(s.size()-1);
        }
        return result;
    }
};