class Solution {
public:
    int findTheWinner(int n, int k) 
    {
       queue<int> q;
        int c=k-1;
        for(int i=1;i<=n;i++) q.push(i);
        while(q.size()>1)
        {
            if(c==0) 
            {
               
                c=k-1;
                
            }
           else
           {
             int t=q.front();
            q.push(t);
            c--;
           }
             q.pop();
        }
        return q.front();
    }
};