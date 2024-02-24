class Solution {
public:
    vector<pair<int,int>>graph[200005]; // child and weight
    vector<int> findAllPeople(int n, vector<vector<int>>&nums, int person) 
    {
        // graph creation
        for(auto &it:nums)
        {
            graph[it[0]].push_back({it[1],it[2]});
            graph[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        pq.push({0,person});
        vector<int>visited(n,0);
        while(pq.size())
        {
            auto [time,node]=pq.top();
            pq.pop();
            if(visited[node])
            {
                continue;
            }
            visited[node]=1;
            for(auto [currentNode,currentTime]:graph[node])
            {
                if(time<=currentTime&&visited[currentNode]==0)
                {
                    pq.push({currentTime,currentNode});
                }
            }
        }
        vector<int>result;
        for(int index=0;index<n;index++)
        {
            if(visited[index])
            {
                result.push_back(index);
            }
        }
        return result;
    }
};