class Solution {
public:
    int maximumLength(vector<int>& nums) {
       int maxLength=0;
        unordered_map<long long,int>mp;
        sort(nums.begin(),nums.end());
        for(auto item:nums) mp[item]++;
        for(int i=0,n=nums.size();i<n;i++){
            int currentLenght=0;
            long long num=nums[i];
            while(mp[num]){
                if(mp[num]<2){
                    currentLenght+=mp[num];
                    mp[num]=0;
                    break;
                }
                mp[num]-=2;
                currentLenght+=2;
                num*=num;
            }
            if(currentLenght%2==0) currentLenght--;
            maxLength=max(maxLength,currentLenght);
        }
        return maxLength;
    }
};