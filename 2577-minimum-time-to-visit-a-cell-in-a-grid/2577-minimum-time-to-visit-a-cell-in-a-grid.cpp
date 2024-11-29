class Solution {
public:
    int getHash(int x,int y,int m){
        return x*m+y;
    }
    pair<int,int>getXY(int hash,int m){
        return {hash/m, hash%m};
    }
    int minimumTime(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        if(mat[0][1]>1&&mat[1][0]>1){
            return -1;
        }
        vector<pair<int,int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        while(pq.size()){
            auto [time,xy]=pq.top();
            pq.pop();
            pair<int,int>currentPoint=getXY(xy, m);
            if(currentPoint.first==n-1&&currentPoint.second==m-1){
                return time;
            }
            if(visited[currentPoint.first][currentPoint.second]){
                continue;
            }
            visited[currentPoint.first][currentPoint.second]=true;
            for(auto &dir:direction){
                int nextX=currentPoint.first+dir.first;
                int nextY=currentPoint.second+dir.second;
                if(nextX>=0&&nextY>=0&&nextX<n&&nextY<m){
                    int nextCellReachTiming = mat[nextX][nextY]+((mat[nextX][nextY]-time)%2==0);
                    pq.push({max(nextCellReachTiming,time+1),getHash(nextX,nextY,m)});
                }
            }
        }
        return -1;
    }
};