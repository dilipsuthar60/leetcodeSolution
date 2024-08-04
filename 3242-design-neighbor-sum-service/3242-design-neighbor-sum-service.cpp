class neighborSum {
public:
    unordered_map<int,pair<int,int>>mp;
    vector<vector<int>>nums;
    int n,m;
    vector<pair<int,int>>adjacent={{-1,0},{1,0},{0,1},{0,-1}};
    vector<pair<int,int>>diagonal={{-1,1},{-1,-1},{1,1},{1,-1}};
    neighborSum(vector<vector<int>>& grid) {
        this->nums=grid;
        this->n=grid.size();
        this->m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[grid[i][j]]={i,j};
            }
        }
    }
    
    int adjacentSum(int value) {
        pair<int,int>point=mp[value];
        int sum=0;
        for(auto &it:adjacent){
            int x=point.first+it.first;
            int y=point.second+it.second;
            if(x>=0&&y>=0&&x<n&&y<m){
                sum+=nums[x][y];
            }
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        pair<int,int>point=mp[value];
        int sum=0;
        for(auto &it:diagonal){
            int x=point.first+it.first;
            int y=point.second+it.second;
            if(x>=0&&y>=0&&x<n&&y<m){
                sum+=nums[x][y];
            }
        }
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */