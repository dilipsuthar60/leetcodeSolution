class Solution {
public:
    vector<int>in;
    vector<int>out;
    int find(vector<vector<int>>&nums,int index){
        if(index>=nums.size()){
            for(int i=0;i<in.size();i++){
                if(in[i]!=out[i]) return -1e9;
            }
            return 0;
        }
        in[nums[index][0]]++;
        out[nums[index][1]]++;
        int take=1+find(nums,index+1);
        in[nums[index][0]]--;
        out[nums[index][1]]--;
        int nottake=find(nums,index+1);
        return max(take,nottake);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        in=vector<int>(n+1,0);
        out=vector<int>(n+1,0);
        return find(requests,0);
    }
};