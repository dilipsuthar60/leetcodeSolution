class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
    {
        int n=nums.size();
        vector<int>party(n+1,0);
        for(int i=1;i<n;i++)
        {
            party[i]=(nums[i]%2==nums[i-1]%2);
            party[i]+=party[i-1];
        }
        vector<bool>ans(queries.size());
        int index=0;
        for(auto query:queries){
            int l=query[0];
            int r=query[1];
            ans[index++]=(party[r]-party[l]==0);
        }
        return ans;
    }
};