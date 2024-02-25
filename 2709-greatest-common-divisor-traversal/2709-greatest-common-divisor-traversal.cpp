class Solution {
public:
    vector<int>parent;
    vector<int>prime;
    const int N=1e5+10;
    vector<int>primeFactor(int n)
    {
        vector<int>factor;
        while(n>1)
        {
            int f=prime[n];
            factor.push_back(f);
            n/=f;
        }
        return factor;
    }
    int find(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void merge(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x==y) return ;
        parent[x]=y;
    }
    bool canTraverseAllPairs(vector<int>& nums) 
    {
        int n=nums.size();
        parent=vector<int>(n+1);
        prime=vector<int>(N);
        iota(parent.begin(),parent.end(),0);
        iota(prime.begin(),prime.end(),0);
        for(int i=2;i*i<N;i++)
        {
            if(prime[i]==i)
            {
                for(int j=2*i;j<N;j+=i)
                {
                    prime[j]=i;
                }
            }
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            for(auto it:primeFactor(nums[i]))
            {
                mp[it].push_back(i);
            }
        }
        for(auto &[_,v]:mp)
        {
            for(int i=1;i<v.size();i++)
            {
                merge(v[i],v[i-1]);
            }
        }
        unordered_map<int,int>group;
        for(int i=0;i<n;i++)
        {
            group[find(i)]++;
        }
        return group.size()==1;
    }
};