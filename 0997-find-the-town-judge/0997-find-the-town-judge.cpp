class Solution {
public:
    int findJudge(int N, vector<vector<int>>& nums)
    {
        vector<int>in(N+1,0),out(N+1,0);
        for(auto &it:nums){
            in[it[1]]++;
            out[it[0]]++;
        }
        for(int i=1;i<=N;i++){
            if(in[i]==N-1&&out[i]==0){
                return i;
            }
        }
        return -1;
    }
};