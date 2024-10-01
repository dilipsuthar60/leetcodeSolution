class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        map<int,multiset<int>>mp;
        for(int i=0;i<values.size();i++){
            mp[labels[i]].insert(values[i]);
            if(mp[labels[i]].size()>useLimit){
                mp[labels[i]].erase(mp[labels[i]].begin());
            }
        }
        int ans=0;
        vector<int>v;
        for(auto &[_,st]:mp){
            for(auto &it:st){
                v.push_back(it);
            }
        }
        sort(v.begin(),v.end());
        int index=0;
        while(v.size()&&index<numWanted){
            ans+=v.back();
            v.pop_back();
            index++;
        }
        return ans;
    }
};