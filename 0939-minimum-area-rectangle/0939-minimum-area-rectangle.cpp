class Solution {
public:
    int getHash(int x,int y){
        return x*97+y*31+7;
    }
    int minAreaRect(vector<vector<int>>& points) {
        int n=points.size();
        unordered_map<int,int>mp;
        for(auto &it:points) mp[getHash(it[0],it[1])]++;
        int ans=1e8;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                if(x1==x2||y1==y2) continue;
                int lookingFor1=getHash(x1,y2);
                int lookingFor2=getHash(x2,y1);
                if(mp.find(lookingFor1)!=mp.end()&&mp.find(lookingFor2)!=mp.end()){
                    ans=min(ans,abs(x1-x2)*abs(y1-y2));
                }
            }
        }
        return ans==1e8?0:ans;
    }
};