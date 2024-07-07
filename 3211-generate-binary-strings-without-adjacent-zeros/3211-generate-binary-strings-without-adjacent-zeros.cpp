class Solution {
public:
    void find(int index,int n,string &curr,vector<string>&res){
        if(index==n){
            res.push_back(curr);
            return ;
        }
        for(char ch='0';ch<='1';ch++){
            if(curr.size()&&curr.back()=='0'&&ch=='0'){
                continue;
            }
            curr.push_back(ch);
            find(index+1,n,curr,res);
            curr.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string>res;
        string curr="";
        find(0,n,curr,res);
        return res;
    }
};