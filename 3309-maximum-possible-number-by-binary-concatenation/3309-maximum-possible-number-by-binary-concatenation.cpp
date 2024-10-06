class Solution {
public:
    int ans=0;
    string getBinary(int n){
        string s;
        while(n){
            s.push_back((n%2)?'1':'0');
            n/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int getCost(vector<string>&nums){
        int ans=0;
        string s;
        for(auto &it:nums) s+=it;
        for(int i=0;i<s.size();i++){
            ans=ans<<1|(s[i]-'0');
        }
        return ans;
    }
    void find(vector<string>&nums,vector<int>&vis,vector<string>&curr,int index){
        if(index>=nums.size()){
            ans=max(ans,getCost(curr));
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=1;
                curr.push_back(nums[i]);
                find(nums,vis,curr,index+1);
                vis[i]=0;
                curr.pop_back();
            }
        }
    }
    int maxGoodNumber(vector<int>& nums) {
        vector<string>v;
        for(auto &it:nums){
            v.push_back(getBinary(it));
        }
        vector<int>vis(nums.size(),0);
        vector<string>curr;
        find(v,vis,curr,0);
        return ans;
    }
};