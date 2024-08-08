class Solution {
public:
    bool isSafe(int x,int y,int n,int m){
        return x>=0&&x<n&&y>=0&&y<m;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rs, int cs) {
        vector<pair<int,int>>direction={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>>ans={{rs,cs}};
        int step=0;
        int d=0;
        while(ans.size()<(rows*cols)){
            if(d == 0 || d == 2) step++;
            for(int i=0;i<step;i++){
                 rs+=direction[d].first;
                 cs+=direction[d].second;
                if(isSafe(rs,cs,rows,cols)){
                    ans.push_back({rs,cs});
                }
            }
            d=(d+1)%4;
        }
        return ans;
    }
};

//   vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // East, South, West, North
//         vector<vector<int>> result = {{rStart, cStart}};
//         int steps = 0, d = 0;
        
//         while (result.size() < rows * cols) {
//             if (d == 0 || d == 2) steps++;
            
//             for (int i = 0; i < steps; i++) {
//                 rStart += directions[d][0];
//                 cStart += directions[d][1];
                
//                 if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
//                     result.push_back({rStart, cStart});
//                 }
                
//                 if (result.size() == rows * cols) return result;
//             }
            
//             d = (d + 1) % 4;
//         }
        
//         return result;