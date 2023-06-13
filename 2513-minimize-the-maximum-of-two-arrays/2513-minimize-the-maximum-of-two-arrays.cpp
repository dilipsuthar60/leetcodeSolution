class Solution {
public:
    int minimizeSet(int d1, int d2, int u1, int u2) 
    {
        long long l=1;
        long long r=1e15;
        int ans=0;
        long lcm=(1l*d1*d2)/(__gcd(d1,d2));
        auto find=[&](long long mid)
        {
            long long n1=mid-(mid/d1);
            long long n2=mid-(mid/d2);
            long long c=mid-(mid/lcm);
            return u1<=n1&&u2<=n2&&(u1+u2<=c);
        };
        while(l<=r)
        {
          long long mid=(l+r)/2;
            if(find(mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};