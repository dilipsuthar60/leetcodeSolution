class Solution {
public:
    int garbageCollection(vector<string>&nums, vector<int>&cost) 
    {
        int n=nums.size();
        int total_p,total_g,total_m;
        total_p=total_g=total_m=0;
        for(int i=0;i<n;i++)
        {
            total_p+=count(nums[i].begin(),nums[i].end(),'P');
            total_g+=count(nums[i].begin(),nums[i].end(),'G');
            total_m+=count(nums[i].begin(),nums[i].end(),'M');
        }
        int sum=0;
        int prev_cost=0;
        for(int i=0;i<n;i++)
        {
            int p=count(nums[i].begin(),nums[i].end(),'P');
            int g=count(nums[i].begin(),nums[i].end(),'G');
            int m=count(nums[i].begin(),nums[i].end(),'M');
            if(i==0)
            {
                sum+=p+m+g;
                total_p-=p;
                total_g-=g;
                total_m-=m;
            }
            else
            {
                sum+=(p+g+m);
                if(total_p)
                {
                    sum+=cost[i-1];
                }
                total_p-=p;
                 if(total_g)
                {
                    sum+=cost[i-1];
                }
                total_g-=g;
                 if(total_m)
                {
                    sum+=cost[i-1];
                }
                total_m-=m;
            }
        }
        return sum;
    }
};