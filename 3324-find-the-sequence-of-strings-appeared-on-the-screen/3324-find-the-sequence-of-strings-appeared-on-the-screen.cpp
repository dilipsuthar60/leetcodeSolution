class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans;
        int n=target.size();
        string curr=string(n,'a');
        int i=0;
        while(true){
            if(ans.size()&&ans.back()==curr) break;
            ans.push_back(curr.substr(0,i+1));
            if(target[i]!=curr[i]){
                curr[i]++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};