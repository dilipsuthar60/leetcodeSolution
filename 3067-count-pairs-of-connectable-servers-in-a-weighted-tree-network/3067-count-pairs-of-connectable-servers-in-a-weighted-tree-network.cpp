class Solution {
public:
    int find(vector<vector<pair<int,int>>>&graph,int node,int currentWeightSum,int signalSpeed,int parent)
    {
        int count=0;
        if(currentWeightSum%signalSpeed==0)
        {
            count++;
        }
        for(auto &[child,childWeight]:graph[node])
        {
            if(child!=parent)
            {
                currentWeightSum+=childWeight;
                count+=find(graph,child,currentWeightSum,signalSpeed,node);
                currentWeightSum-=childWeight;
            }
        }
        return count;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) 
    {  
        int size=edges.size();
        vector<vector<pair<int,int>>>graph(size+10);
        for(auto &edge:edges)
        {
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<int>result(size+1);
        for(int index=0;index<=size;index++)
        {
            vector<int>pathCount;
            for(auto it:graph[index])
            {
                int count=find(graph,it.first,it.second,signalSpeed,index);
                pathCount.push_back(count);
            }
            for(int i=0;i<pathCount.size()-1;i++)
            {
                for(int j=i+1;j<pathCount.size();j++)
                {
                    result[index]+=pathCount[i]*pathCount[j];
                }
            }
        }
        return result;
    }
};