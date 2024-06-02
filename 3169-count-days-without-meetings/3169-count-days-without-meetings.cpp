class Solution {
public:
    vector<vector<int>>merge(vector<vector<int>>&nums){
        vector<vector<int>>result;
        result.push_back(nums.front());
        for(int i=1;i<nums.size();i++)
        {
            if(result.back()[1]<nums[i][0]){
                result.push_back(nums[i]);
            }
            else{
                result.back()[0]=min(result.back()[0],nums[i][0]);
                result.back()[1]=max(result.back()[1],nums[i][1]);
            }
        }
        return result;
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        auto intervals=merge(meetings);
        int busyDay=0;
        for(auto it:intervals){
            busyDay+=(it[1]-it[0]+1);
        }
        return days-busyDay;
    }
};