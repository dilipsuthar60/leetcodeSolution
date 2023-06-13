class Solution {
public:
    const int N=2e5+10;
    int bit[210000];
    void update(int i,int sum)
    {
        i++;
        while(i<N)
        {
            bit[i]=max(bit[i],sum);
            i+=(i&-i);
        }
    }
    int find(int i)
    {
        i++;
        int max_sum=-1;
        while(i>0)
        {
            max_sum=max(max_sum,bit[i]);
            i-=(i&-i);
        }
        return max_sum;
    }
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& q)
    {
        memset(bit,-1,sizeof(bit));
        int n=nums1.size();
        vector<pair<int,int>>nums;
        set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(nums2[i]);
            nums.push_back({nums1[i],nums2[i]});
        }
        for(int i=0;i<q.size();i++)
        {
            s.insert(q[i][1]);
            q[i].push_back(i);
        }
        unordered_map<int,int>id;
        int index=s.size();
        for(auto it:s)
        {
            id[it]=index--;
        }
        sort(nums.rbegin(),nums.rend());
        sort(q.rbegin(),q.rend());
        vector<int>ans(q.size(),-1);
        for(int i=0,j=0;i<q.size();i++)
        {
            int x=q[i][0];
            int y=id[q[i][1]];
            int index=q[i][2];
            while(j<n&&nums[j].first>=x)
            {
                update(id[nums[j].second],nums[j].first+nums[j].second);
                j++;
            }
            ans[index]=find(y);
        }
        return ans;
    }
};   