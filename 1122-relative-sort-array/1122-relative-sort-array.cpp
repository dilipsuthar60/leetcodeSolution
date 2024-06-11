class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        sort(arr1.begin(),arr1.end());
        unordered_map<int,int>mp;
        vector<int>result;
        for(auto it:arr1){
            mp[it]++;
        }
        int index=0;
        for(auto it:arr2){
            auto freq=mp[it];
            while(freq--){
                result.push_back(it);
                index++;
            }
            mp.erase(it);
        }
        for(int i=0;i<arr1.size();i++)
        {
            if(mp.find(arr1[i])!=mp.end()){
                result.push_back(arr1[i]);
            }
        }
        return result;
    }
};