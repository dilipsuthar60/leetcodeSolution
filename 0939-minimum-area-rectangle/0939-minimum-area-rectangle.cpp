class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n=points.size();
        unordered_map<int,unordered_set<int>>mp;
        for(auto point:points){
            mp[point[0]].insert(point[1]);
        }
        int area=1e9;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(points[i][0]==points[j][0]||points[i][1]==points[j][1]){
                    continue;
                }
                if(mp[points[i][0]].count(points[j][1])&&mp[points[j][0]].count(points[i][1])){
                    area=min(area,abs(points[i][0]-points[j][0])*abs(points[i][1]-points[j][1]));
                }
            }
        }
        return area==1e9?0:area;
    }
};