class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans;
        int n=target.size();
        string curr="";
        for(int i=0;i<n;i++){
            char ch;
            for( ch='a';ch<=target[i];ch++){
                ans.push_back(curr+ch);
            }
            curr+=(ch-1);
        }
        return ans;
    }
};