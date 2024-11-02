class Solution {
public:
    bool isCircularSentence(string s) {
        stringstream ss(s);
        vector<string>nums;
        string curr;
        while(ss>>curr){
            nums.push_back(curr);
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i-1].back()!=nums[i].front()) return false;
        }
        if(nums.front().front()!=nums.back().back()) return false;
        return true;
    }
};