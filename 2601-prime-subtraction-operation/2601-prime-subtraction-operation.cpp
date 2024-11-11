class Solution {
public:
    bool isPrime(int n){
        if(n==0||n==1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int>prime;
        for(int i=2;i<3001;i++){
            if(isPrime(i)){
                prime.push_back(i);
            }
        }
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=nums[i+1]){
                for(auto &it:prime){
                    if(it<nums[i]&&(nums[i]-it)<nums[i+1]){
                        nums[i]=nums[i]-it;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]>=nums[i+1]) return false;
        }
        return true;
    }
};