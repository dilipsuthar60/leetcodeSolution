class Solution {
public:
    int dp[51][51][51][5];
    int find(int x,int y,int z,string prev)
    {
        int start=0;
        if(prev=="AA")
        {
            start=1;
        }
        if(prev=="AB")
        {
            start=2;
        }
        if(prev=="BB")
        {
            start=3;
        }
        if(dp[x][y][z][start]!=-1)
        {
            return dp[x][y][z][start];
        }
        int ans=0;
        if(prev=="AA")
        {
            if(y>0)
            ans+=2+find(x,y-1,z,"BB");
        }
        else if(prev=="BB")
        {
            int f1=0;
            int f2=0;
            if(x>0)
            {
                f1=f1+2+find(x-1,y,z,"AA");
            }
            if(z>0)
            {
                f2=f2+2+find(x,y,z-1,"AB");
            }
            ans+=max(f1,f2);
        }
        else if(prev=="AB")
        {
            int f1,f2;
            f1=f2=0;
            if(x>0)
            {
                f1=f1+2+find(x-1,y,z,"AA");
            }
            if(z>0)
            {
                f2=f2+2+find(x,y,z-1,"AB");
            }
            ans+=max(f1,f2);
        }
        return dp[x][y][z][start]= ans;
    }
    int longestString(int x, int y, int z)
    {
        memset(dp,-1,sizeof(dp));
        int f1=find(x,y,z,"AA");
        memset(dp,-1,sizeof(dp));
        int f2=find(x,y,z,"BB");
        memset(dp,-1,sizeof(dp));
        int f3=find(x,y,z,"AB");
        return max({f1,f2,f3});
    }
};