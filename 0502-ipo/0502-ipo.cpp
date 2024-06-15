class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) 
    {
        int n=p.size();
        vector<pair<int,int>>nums;
        for(int i=0;i<n;i++)
        {
            nums.push_back({c[i],p[i]});
        }
        int j=0;
        sort(nums.begin(),nums.end());
        priority_queue<int>pq;
        while(k--)
        {
            while(j<n&&nums[j].first<=w)
            {
                pq.push(nums[j].second);
                j++;
            }
            if(pq.size()==0)
            {
                break;
            }
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};