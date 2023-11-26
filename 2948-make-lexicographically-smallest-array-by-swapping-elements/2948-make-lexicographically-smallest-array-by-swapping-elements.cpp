class Solution {
public:
    vector<vector<int>>v;
    vector<int>parent;
    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void merge(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x!=y)
        {
            parent[x]=y;
        }
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        for(int i=1;i<n;i++)
        {
            if(v[i][0]-v[i-1][0]<=limit)
            {
                merge(v[i][1],v[i-1][1]);
            }
        }
        vector<vector<int>>group(n+1);
        for(int i=0;i<n;i++)
        {
            group[find(i)].push_back(i);
        }
        vector<int>ans=nums;
        for(int i=0;i<n;i++)
        {
            vector<int>value;
            for(auto it:group[i])
            {
                value.push_back(nums[it]);
            }
            sort(value.begin(),value.end());
            int index=0;
            for(auto it:value)
            {
                ans[group[i][index]]=it;
                index++;
            }
        }
        return ans;
    }
};