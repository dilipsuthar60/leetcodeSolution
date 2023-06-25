class Solution {
public:
    vector<int> countServers(int total, vector<vector<int>>&nums, int x, vector<int>& que) 
    {
        vector<vector<int>>q;
        int n=nums.size();
        for(int i=0;i<que.size();i++)
        {
            q.push_back({que[i],i});
        }
        vector<int>ans(q.size());
        sort(q.begin(),q.end());
        unordered_map<int,int>mp;
        sort(nums.begin(),nums.end(),[&](auto &a,auto &b){return a[1]<b[1];});
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0,j=0;i<q.size();i++)
        {
            while(j<n&&nums[j][1]<=q[i][0])
            {
                mp[nums[j][0]]++;
                pq.push({nums[j][1],nums[j][0]});
                j++;
            }
            while(pq.size()&&pq.top().first<(q[i][0]-x))
            {
                mp[pq.top().second]--;
                if(mp[pq.top().second]==0)
                {
                    mp.erase(pq.top().second);
                }
                pq.pop();
            }
            ans[q[i][1]]=total-mp.size();
        }
        return ans;
    }
};