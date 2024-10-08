class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n=points.size();
        map<pair<int,int>,int>mp;
        for(auto &it:points) mp[{it[0],it[1]}]++;
        int ans=1e8;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                if(x1==x2||y1==y2) continue;
                pair<int,int>lookingFor1={x1,y2};
                pair<int,int>lookingFor2={x2,y1};
                if(mp.count(lookingFor1)>0&&mp.count(lookingFor2)>0){
                    ans=min(ans,abs(x1-x2)*abs(y1-y2));
                }
            }
        }
        return ans==1e8?0:ans;
    }
};