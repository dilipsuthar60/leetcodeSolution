class Solution {
public:
    vector<int>nums;
    long long dp[20005][100];
    long long find(vector<int>&nums,vector<int>&robot,int index,int robotCount){
        if(robotCount==robot.size()){
            return 0;
        }
        if(index==nums.size()) return 1e17;
        if(dp[index][robotCount]!=-1) return dp[index][robotCount];
        long long take=abs(robot[robotCount]-nums[index])+find(nums,robot,index+1,robotCount+1);
        long long notTake=find(nums,robot,index+1,robotCount);
        return dp[index][robotCount] = min(take,notTake);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        memset(dp,-1,sizeof(dp));
        for(auto &fac:factory){
            for(int i=0;i<fac[1];i++){
                nums.push_back(fac[0]);
            }
        }
        sort(nums.begin(),nums.end());
        sort(robot.begin(),robot.end());
        return find(nums,robot,0,0);
    }
};