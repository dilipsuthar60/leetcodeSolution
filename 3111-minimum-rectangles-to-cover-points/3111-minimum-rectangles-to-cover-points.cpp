class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int n=points.size();
        map<int,int>mp;
        for(auto &point:points){
            mp[point[0]]++;
        }
        int counter=1;
        auto iter=mp.begin();
        int previous = iter->first;
        while(iter!=mp.end()){
            if(iter->first-previous>w){
                counter++;
                previous=iter->first;
            }
            iter++;
        }
        return counter;
    }
};