class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count=0;
        multiset<int>s;
        for(int i=0,n=nums.size(),j=0;i<n;i++)
        {
            s.insert(nums[i]);
            while(s.size()>1&&(*s.rbegin()-*s.begin())>2)
            {
                s.erase(s.find(nums[j++]));
            }
            count+=(i-j+1);
        }
        return count;
    }
};