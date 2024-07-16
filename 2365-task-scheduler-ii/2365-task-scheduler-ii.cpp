class Solution {
public:
    long long taskSchedulerII(vector<int>& task, int space) {
        unordered_map<long long,long long>mp;
        int n=task.size();
        long long day=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(task[i])!=mp.end()&&day-mp[task[i]]<=space)
            {
                day=mp[task[i]]+space+1;
            }
            mp[task[i]]=day++;
        }
        return day;
    }
};