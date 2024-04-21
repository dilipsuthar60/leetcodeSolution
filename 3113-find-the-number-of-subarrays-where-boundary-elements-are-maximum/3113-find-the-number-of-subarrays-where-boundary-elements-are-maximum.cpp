class Solution {
public:
    int tree[4*100000]={0};
    void build(int index,int l,int r,vector<int>&nums)
    {
        if(l==r)
        {
            tree[index]=nums[l];
            return ;
        }
        int mid=(l+r)/2;
        build(2*index+1,l,mid,nums);
        build(2*index+2,mid+1,r,nums);
        tree[index]=max(tree[2*index+1],tree[2*index+2]);
    }
    int query(int index,int sl,int sr,int l,int r)
    {
        if(sr<l||r<sl) return -1e8;
        if(l<=sl&&sr<=r) return tree[index];
        int mid=(sl+sr)/2;
        int left=query(2*index+1,sl,mid,l,r);
        int right=query(2*index+2,mid+1,sr,l,r);
        return max(left,right);
    }
    long long numberOfSubarrays(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        build(0,0,n-1,nums);
        long long answer=0;
        for(auto &[key,value]:mp)
        {
            long long count=1;
            for(int i=1;i<value.size();i++)
            {
                int maxValueRange = query(0,0,n-1,value[i-1],value[i]);
                if(maxValueRange==key)
                {
                    count++;
                }
                else
                {
                    answer+=(count*(count+1))/2;
                    count=1;
                }
            }
             answer+=(count*(count+1))/2;
        }
        return answer;
    }
};