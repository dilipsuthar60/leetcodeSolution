class Solution {
public:
    int N;
    vector<int>bit;
    void update(int i,int val)
    {
        while(i<N)
        {
            bit[i]+=val;
            i+=(i&-i);
        }
    }
    int find(int i)
    {
        int sum=0;
        while(i>0)
        {
            sum+=bit[i];
            i-=(i&-i);
        }
        return sum;
    }
    long long countOperationsToEmptyArray(vector<int>& nums)
    {
        int n=nums.size();
        bit=vector<int>(n+10);
        N=bit.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            update(i+1,1);
            v.push_back({nums[i],i+1});
        }
        long long ans=0;
        sort(v.begin(),v.end());
        int last=1;
        for(int i=0;i<n;i++)
        {
            if(v[i].second>=last)
            {
                ans+=find(v[i].second)-find(last-1);
                update(v[i].second,-1);
            }
            else
            {
                ans+=find(n+1)-find(last-1)+find(v[i].second);;
                update(v[i].second,-1);
            }
            last=v[i].second;
        }
        return ans;
    }
};