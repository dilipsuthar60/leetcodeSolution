class Solution {
public:
    vector<int>dp[100009];
    bool canFinish(int num, vector<vector<int>>&graph) 
    {
        vector<int>in(num+1,0);
        for(auto it:graph)
        {
            dp[it[1]].push_back(it[0]);
            in[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<num;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }
        int count=0;
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            count++;
            for(auto it:dp[temp])
            {
                in[it]--;
                if(in[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return count==num;
    }
};