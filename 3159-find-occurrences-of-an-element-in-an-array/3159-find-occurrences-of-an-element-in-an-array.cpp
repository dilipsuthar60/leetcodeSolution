class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n=nums.size();
        vector<int>storeIndexes;
        int index=0;
        for(auto &it:nums) {
            if(it==x){
                storeIndexes.push_back(index);
            }
            index++;
        }
        vector<int>ans((int)queries.size());
        index=0;
        for(auto &query:queries){
            ans[index++]=(storeIndexes.size()<query)?-1:storeIndexes[query-1];
        }
        return ans;
    }
};