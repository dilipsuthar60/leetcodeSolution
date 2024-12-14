class Solution {
public:
    int maximumRobots(vector<int>& charge, vector<int>& run, long long target) 
    {
        int len=0;
        multiset<long long,greater<long long>>s;
        long long curr_sum=0;
        for(int i=0,n=run.size(),j=0;i<n;i++)
        {
            curr_sum+=run[i];
            s.insert(charge[i]);
            while(*s.begin()+1ll*(i-j+1)*curr_sum>target)
            {
                curr_sum-=run[j];
                s.erase(s.find(charge[j]));
                j++;
            }
            len=max(len,i-j+1);
        }
        return len;
    }
};