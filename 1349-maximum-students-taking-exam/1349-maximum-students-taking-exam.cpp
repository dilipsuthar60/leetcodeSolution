class Solution {
public:
    int dp[9][9][(1<<8)+1][(1<<8)+1];
    int n,m;
    int setbit(int mask,int x)
    {
        if(x<0)
        {
            return 1;
        }
        return ((mask&(1<<x))==0);
    }
    int find(vector<vector<char>>&mat,int i,int j,int prev,int mask)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][j][prev][mask]!=-1)
        {
            return dp[i][j][prev][mask];
        }
        int ans=0;
        if(setbit(prev,j-1)&&setbit(prev,j+1)&&setbit(mask,j-1)&&mat[i][j]=='.')
        {
            if(j==m-1)
            {
                ans=max(ans,1+find(mat,i+1,0,mask|(1<<j),0));
            }
            else
            {
                ans=max(ans,1+find(mat,i,j+1,prev,mask|(1<<j)));
            }
        }
        if(j==m-1)
        {
            ans=max(ans,find(mat,i+1,0,mask,0));
        }
        else
        {
            ans=max(ans,find(mat,i,j+1,prev,mask));
        }
        return dp[i][j][prev][mask]= ans;
    }
    int maxStudents(vector<vector<char>>& seats) 
    {
        memset(dp,-1,sizeof(dp));
        n=seats.size();
        m=seats[0].size();
        return find(seats,0,0,0,0);
    }
};