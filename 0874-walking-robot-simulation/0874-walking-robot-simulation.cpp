class Solution {
public:
    int robotSim(vector<int>& nums, vector<vector<int>>& obs) {
        int size=nums.size();
        set<pair<int,int>>s;
        vector<pair<int,int>>direction = {{0,1},{1,0},{0,-1},{-1,0}};
        int maximumSquredDistance=0;
        for(auto&it:obs){
            s.insert({it[0],it[1]});
        }
        int d=0;
        int x=0;
        int y=0;
        for(int i=0;i<size;i++){
            if(nums[i]==-1){
                d=(d+1)%4;
            }
            else if(nums[i]==-2){
                d=(d+3)%4;
            }
            else{
                for(int k=0;k<nums[i];k++){
                    int nextX=x+direction[d].first;
                    int nextY=y+direction[d].second;
                    if(s.find({nextX,nextY})!=s.end()){
                        break;
                    }
                    x=nextX;
                    y=nextY;
                }
                maximumSquredDistance=max(maximumSquredDistance,x*x+y*y);
            }
        }
        return maximumSquredDistance;
    }
};