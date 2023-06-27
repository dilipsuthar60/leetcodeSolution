class Solution {
public:
    int total=0;
    int N=0;
    int n;
    int minimumDifference(vector<int>& nums) 
    {
        n=nums.size();
        N=n/2;
        vector<int>left[N+1],right[N+1];
        total=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<(1<<N);i++)
        {
            int left_sum=0;
            int right_sum=0;
            int set_bit=0;
            for(int j=0;j<N;j++)
            {
                if(i&(1<<j))
                {
                    set_bit++;
                    left_sum+=nums[j];
                    right_sum+=nums[j+N];
                }
            }
            left[set_bit].push_back(left_sum);
            right[set_bit].push_back(right_sum);
        }
        int ans=1e9+10;
        for(int size=0;size<=N;size++)
        {
            int new_size=N-size;
            sort(right[new_size].begin(),right[new_size].end());
            for(auto &value:left[size])
            {
                auto it=lower_bound(right[new_size].begin(),right[new_size].end(),total/2-value);
                if(it!=right[new_size].end())
                {
                    ans=min(ans,abs(total-2*(*it+value)));
                }
                // if(it!=right[new_size].begin())
                // {
                //     it--;
                //     ans=min(ans,abs(total-2*(*it+value)));
                // }
            }
        }
        return ans;
    }
};