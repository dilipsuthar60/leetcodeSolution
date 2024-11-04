class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n=nums.size();
        int mp[201];
        memset(mp,0,sizeof(mp));
        for(auto &point:nums){
            mp[point[0]]++;
            mp[point[1]+1]--;
        }
        int ans=0;
        for(int i=0,sum=0;i<201;i++){
            sum+=mp[i];
            if(sum>0) ans++;
        }
        return ans;
    }
};