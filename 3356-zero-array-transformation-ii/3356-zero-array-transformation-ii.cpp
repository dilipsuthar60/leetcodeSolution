class Solution {
public:
    bool find(vector<int>&nums,vector<vector<int>>&queries,int mid){
        int n=nums.size();
        vector<int>prefix(n+5,0);
        for(int i=0;i<mid;i++){
            int x=queries[i][0];
            int y=queries[i][1];
            int value=queries[i][2];
            prefix[x]+=value;
            prefix[y+1]-=value;
        }
        for(int i=1;i<n;i++){
            prefix[i]+=prefix[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>prefix[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l=0;
        int r=queries.size();
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(find(nums,queries,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};