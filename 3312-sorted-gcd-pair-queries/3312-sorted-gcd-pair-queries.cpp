class Solution {
public:
    vector<int>getFactor(int n){
        vector<int>nums;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                nums.push_back(i);
                if(n/i!=i) nums.push_back(n/i);
            }
        }
        return nums;
    }
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxElement=*max_element(nums.begin(),nums.end());
        long long gcd[maxElement+1];
        memset(gcd,0,sizeof(gcd));
        for(auto &num:nums){
            for(auto &f:getFactor(num)){
                gcd[f]++;
            }
        }
        
        for(int i=maxElement;i>=1;i--){
            gcd[i]=gcd[i]*(gcd[i]-1)/2;
            for(int j=2*i;j<=maxElement;j+=i){
                gcd[i]-=gcd[j];
            }
        }
        
        for(int i=1;i<=maxElement;i++){
            gcd[i]+=gcd[i-1];
        }
        vector<int>ans;
        for(auto &query:queries){
            auto index = lower_bound(gcd,gcd+maxElement,query+1)-gcd;
            ans.push_back(index);
        }
        return ans;
    }
};