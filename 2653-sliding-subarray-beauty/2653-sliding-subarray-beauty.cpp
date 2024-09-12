class Solution {
public:
    int getKthminimum(vector<int>&hash,int k){
        int sum=0;
        for(int i=0;i<hash.size();i++){
            sum+=hash[i];
            if(sum>=k){
                return i-50;
            }
        }
        return -1;
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int>ans;
        int n=nums.size();
        vector<int>hash(101,0);
        for(int i=0;i<k;i++){
            hash[nums[i]+50]++;
        }
        int value=getKthminimum(hash,x);
        ans.push_back(value>0?0:value);
        for(int i=k;i<n;i++){
            hash[nums[i-k]+50]--;
            hash[nums[i]+50]++;
            value=getKthminimum(hash,x);
            ans.push_back(value>0?0:value);
        }
        return ans;
    }
};