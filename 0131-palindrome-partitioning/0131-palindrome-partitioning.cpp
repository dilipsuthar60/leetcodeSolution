class Solution {
public:
    vector<vector<int>>computePalindromincSubstring(string&s){
        int n=s.size();
        vector<vector<int>>preComputeSubstring(n,vector<int>(n,0));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){
                    preComputeSubstring[i][j]=1;
                }
                else if(gap==1){
                    preComputeSubstring[i][j]=(s[i]==s[j]);
                }
                else{
                    if(s[i]==s[j]&&preComputeSubstring[i+1][j-1]){
                        preComputeSubstring[i][j]=1;
                    }
                }
            }
        }
        return preComputeSubstring;
    }
    void find(string &s,int index,vector<vector<int>>&preComputeSubstring,vector<string>&curr,vector<vector<string>>&result){
        if(index==s.size()){
            result.push_back(curr);
            return ;
        }
        for(int i=index;i<s.size();i++)
        {
            if(preComputeSubstring[index][i])
            {
                curr.push_back(s.substr(index,i-index+1));
                find(s,i+1,preComputeSubstring,curr,result);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<int>>preComputeSubstring = computePalindromincSubstring(s);
        vector<vector<string>>result;
        vector<string>curr;
        find(s,0,preComputeSubstring,curr,result);
        return result;
    }
};