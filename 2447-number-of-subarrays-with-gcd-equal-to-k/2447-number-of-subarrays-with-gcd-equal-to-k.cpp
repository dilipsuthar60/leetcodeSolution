class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>prev;
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>curr;
            for(auto &[key,value]:prev){
                int currentGcd=__gcd(key,nums[i]);
                curr[currentGcd]+=value;
            }
            curr[nums[i]]++;
            if(curr.find(k)!=curr.end()){
                ans+=curr[k];
            }
            prev=curr;
        }
        return ans;
    }
};