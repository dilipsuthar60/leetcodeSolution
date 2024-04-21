class Solution {
public:
    bool isPrime(int number)
    {
        if(number<=1) return false;
        for(int i=2;i*i<=number;i++) if(number%i==0) return false;
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int first=-1;
        int len=0;
        for(int i=0,n=nums.size();i<n;i++)
        {
            if(isPrime(nums[i]))
            {
                if(first==-1)
                {
                    first=i;
                }
                cout<<i<<" "<<first<<endl;
                len=max(len,i-first);
            }
        }
        return len;
    }
};