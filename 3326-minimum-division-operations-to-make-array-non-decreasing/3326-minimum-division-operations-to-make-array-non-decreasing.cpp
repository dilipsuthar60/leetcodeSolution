class Solution {
public:
    int getDivisor(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return i;
        }
        return -1;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                int value = getDivisor(nums[i]);
                if(value==-1||value>nums[i+1]) return -1;
                nums[i]=value;
                ans++;
            }
        }
        return ans;
    }
};