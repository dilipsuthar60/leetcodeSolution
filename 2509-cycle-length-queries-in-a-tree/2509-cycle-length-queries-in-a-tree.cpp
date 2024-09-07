class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto &query:queries){
            int a=query[0];
            int b=query[1];
            int count=0;
            while(a!=b){
                if(a<b){
                    b/=2;
                }
                else{
                    a/=2;
                }
                count++;
            }
            ans.push_back(count+1);
        }
        return ans;
    }
};