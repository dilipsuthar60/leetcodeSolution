class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>&nums, int st) 
    {
        map<int, int> m{{0, 0}};
        for(auto& f:nums){
            m[f[0]]+=f[2];
            m[f[1]+1]-=f[2];
        }
        
        int sum = 0;
        for(auto& [v,c]:m)
        {
            sum+=c;
            c=sum;
        }
        vector<int>persons(st);
        iota(persons.begin(),persons.end(),1);
        vector<int> ans;
        for(int t:persons)
        {
            auto it=m.upper_bound(t);
            ans.push_back(prev(it)->second);
        }
        return ans;
    }
};