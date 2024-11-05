class Solution {
public:
    bool find(vector<vector<int>>&nums,string &s,int mid){
        int hash[26]={0};
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i][0])<=mid&&abs(nums[i][1])<=mid){
                hash[s[i]-'a']++;
            }
        }
        for(int i=0;i<26;i++){
            if(hash[i]>1) return false;
        }
        return true;
    }
    int maxPointsInsideSquare(vector<vector<int>>& nums, string s) {
        int n=nums.size();
        int l=0;
        int r=1e9;
        int squareSize=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(find(nums,s,mid)){
                squareSize=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        int pointCount=0;
        for(int i=0;i<n;i++){
            if(abs(nums[i][0])<=squareSize&&abs(nums[i][1])<=squareSize){
                pointCount++;
            }
        }
        return pointCount;
    }
};