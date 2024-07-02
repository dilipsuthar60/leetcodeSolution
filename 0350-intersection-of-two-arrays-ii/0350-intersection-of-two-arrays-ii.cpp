class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1,mp2;
        for(auto &it:nums1) mp1[it]++;
        for(auto &it:nums2) mp2[it]++;
        vector<int>result;
        for(auto &it:nums1){
            if(mp1.find(it)!=mp1.end()&&mp2.find(it)!=mp2.end()){
                if(--mp1[it]==0){
                    mp1.erase(it);
                }
                if(--mp2[it]==0){
                    mp2.erase(it);
                }
                result.push_back(it);
            }
        }
        return result;
    }
};