class Solution {
public:
    vector<long long>findPalindrom(long long num){
        string s=to_string(num);
        int n =s.size();
        unordered_set<long long>st;
        st.insert(pow(10,n)+1);
        st.insert(pow(10,n-1)-1);
        int mid=(n+1)/2;
        long long prefix=stoll(s.substr(0,mid));
        for(int i=-1;i<=1;i++){
            string front=to_string(prefix+i);
            string back="";
            if(n&1){
                back=front.substr(0,front.size()-1);
            }else{
                back=front.substr(0,front.size());
            }
            reverse(back.begin(),back.end());
            front+=back;
            st.insert(stoll(front));
        }
        vector<long long>v;
        for(auto &it:st){
            v.push_back(it);
        }
        return v;
    }
    bool isPalindron(long long x){
        long long y=0;
        while(x){
            y=y*10+x%10;
            x/=10;
        }
        return x==y;
    }
    long long minimumCost(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long medien = (n&1)?(nums[(n-1)/2]+nums[n/2])/2:nums[n/2];
        vector<long long>v=findPalindrom(medien);
        if(isPalindron(medien)) v.push_back(medien);
        long long ans=1e18;
        for(auto &it:v){
            long long cost=0;
            for(int i=0;i<n;i++){
                cost+=abs(nums[i]-it);
            }
            ans=min(ans,cost);
        }
        return ans;
    }
};