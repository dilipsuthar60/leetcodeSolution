class Solution {
public:
    void find(string &s,unordered_set<string>&st){
        st.insert(s);
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                swap(s[i],s[j]);
                st.insert(s);
                swap(s[i],s[j]);
            }
        }
    }
    string getIntToString(int n,int digit){
        string s=to_string(n);
        string leadingZero="";
        while(s.size()+leadingZero.size()<digit){
            leadingZero+="0";
        }
        return leadingZero+s;
    }
    int countPairs(vector<int>& nums) {
        int n=nums.size();
        int maximumDigit=0;
        for(int i=0;i<n;i++){
            maximumDigit=max(maximumDigit,nums[i]);
        }
        int digit=to_string(maximumDigit).size();
        vector<string>v;
        for(int i=0;i<n;i++){
            v.push_back(getIntToString(nums[i],digit));
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                unordered_set<string>st;
                find(v[j],st);
                for(auto &it:st){
                    if(it==v[i]){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};