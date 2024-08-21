class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans=0;
        unordered_map<int,int>mp;
        for(auto &number:nums1){
            for(int i=1;i*i<=number;i++){
                if(i*i==number) mp[i]++;
                else if(number%i==0){ mp[i]++,mp[number/i]++;}
            }
        }
        for(auto &num:nums2){
            int looking=num*k;
            if(mp.find(looking)!=mp.end()) ans+=mp[looking];
        }
        return ans;
    }
};