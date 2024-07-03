class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq){
        vector<long long>result;
        int n=nums.size();
        map<long long,long long>most;
        unordered_map<long long,long long>idToFreq;
        for(int i=0;i<n;i++)
        {
            if(idToFreq.find(nums[i])==idToFreq.end()){
                idToFreq[nums[i]]+=freq[i];
                most[idToFreq[nums[i]]]++;
            }
            else{
                most[idToFreq[nums[i]]]--;
                if(most[idToFreq[nums[i]]]==0){
                    most.erase(idToFreq[nums[i]]);
                }
                idToFreq[nums[i]]+=freq[i];
                most[idToFreq[nums[i]]]++;
            }
            result.push_back((*most.rbegin()).first);
        }
        return result;
    }
};