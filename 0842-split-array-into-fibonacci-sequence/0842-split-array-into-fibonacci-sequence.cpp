class Solution {
public:
    bool find(string &s,int index,vector<int>&ans){
        if(index>=s.size() && ans.size()>2) return true;
        long long num=0;
        for(int i=index;i<s.size();i++){
            if(s[index]=='0'&&i>index) return false;
            num=num*10+(s[i]-'0');
            if(num<0||num>INT_MAX) return false;
            if(ans.size()<2||(1ll*ans.back()+1ll*ans[ans.size()-2]==num)){
                ans.push_back(num);
                if(find(s,i+1,ans)) return true;
                ans.pop_back();
            }
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string num) {
        vector<int>ans;
        find(num,0,ans);
        return ans;
    }
};