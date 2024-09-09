class Solution {
public:
    int n;
    int dis[20][20];
    int dp[16][(1<<16)+1];
    vector<pair<int,int>>dir={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
    void bfs(int index,vector<vector<int>>&pos,int a,int b){
        queue<pair<int,int>>q;
        q.push({a,b});
        vector<vector<int>>d(50,vector<int>(50,1e8));
        d[a][b]=0;
        while(q.size()){
            auto [x,y]=q.front();
            q.pop();
            for(auto &it:dir){
                int nx=x+it.first;
                int ny=y+it.second;
                if(nx>=0&&ny>=0&&nx<50&&ny<50&&d[nx][ny]>d[x][y]+1){
                    d[nx][ny]=d[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        for(int i=0;i<n;i++){
            dis[index][i]=d[pos[i][0]][pos[i][1]];
        }
    }
    int find(vector<vector<int>>&nums,int index,int mask,int turn){
        if(mask==((1<<n)-1)) return 0;
        int ans=(turn)?-1e8:1e8;
        if(dp[index][mask]!=-1) return dp[index][mask];
        for(int i=0;i<nums.size();i++){
            if(mask&(1<<i)) continue;
            int value = dis[index][i];
            if(turn){
                ans=max(ans,value+find(nums,i,mask|(1<<i),turn^1));
            }
            else{
                ans=min(ans,value+find(nums,i,mask|(1<<i),turn^1));
            }
        }
        return dp[index][mask]= ans;
    }
    int maxMoves(int kx, int ky, vector<vector<int>>& pos) {
        pos.insert(pos.begin(),{kx,ky});
        memset(dp,-1,sizeof(dp));
        n=pos.size();
        for(int i=0;i<n;i++){
            bfs(i,pos,pos[i][0],pos[i][1]);
        }
        return find(pos,0,1,1);
    }
};