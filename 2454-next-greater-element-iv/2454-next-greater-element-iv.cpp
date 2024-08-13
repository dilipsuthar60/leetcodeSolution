class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>v;
        set<int>s;
        for(int i=0;i<n;i++){
            v.push_back({-nums[i],i});
        }
        sort(v.begin(),v.end());
        vector<int>ans(n,-1);
        for(auto&[num,i]:v){
            auto it=s.lower_bound(i);
            if(it!=s.end()){
                it++;
                if(it!=s.end()){
                  ans[i]=nums[*it];   
                }
            }
            s.insert(i);
        }
        return ans;
    }
};