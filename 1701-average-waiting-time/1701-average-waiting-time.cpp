class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& nums) 
    {
        int n=nums.size();
        double waiting_time=0.0;
        double curr_time=0.0;
        for(auto it:nums)
        {
            curr_time=max(curr_time,1.0*it[0])+it[1];
            waiting_time+=curr_time-it[0];
        }
        return double(waiting_time/(nums.size()));
    }
};