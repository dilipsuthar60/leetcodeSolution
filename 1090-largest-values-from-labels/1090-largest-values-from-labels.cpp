class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int,int>>v;
        for(int i=0;i<labels.size();i++){
            v.push_back({values[i],labels[i]});
        }
        sort(v.rbegin(),v.rend());
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0,count=0;i<v.size()&&count<numWanted;i++){
            if(++mp[v[i].second]<=useLimit){
                ans+=v[i].first;
                count++;
            }
        }
        return ans;
    }
};