class Solution {
public:
    int slidingPuzzle(vector<vector<int>>&mat)
    {
        int n=mat.size();
        int m=mat[0].size();
        string s="";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                s+=(char(mat[i][j]+'0'));
            }
        }
        string target="123450";
        queue<string>q;
        q.push(s);
        set<string>vis;
        vis.insert(s);
        vector<vector<int>>v={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        int level=0;
        while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
                if(temp==target)
                {
                    return level;
                }
                int len=temp.size();
                int pos_zero=temp.find('0');
                for(auto it:v[pos_zero])
                {
                    swap(temp[it],temp[pos_zero]);
                    if(vis.find(temp)==vis.end())
                    {
                        q.push(temp);
                        vis.insert(temp);
                    }
                    swap(temp[it],temp[pos_zero]);    
                }
            }
            level++;
        }
        return -1;
    }
};