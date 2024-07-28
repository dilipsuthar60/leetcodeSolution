class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        int singleDigitSum=0;
        int doubleDigitSum=0;
        for(int i=0,n=nums.size();i<n;i++){
            string s=to_string(nums[i]);
            if(s.size()==1){
                singleDigitSum+=nums[i];
            }
            if(s.size()==2){
                doubleDigitSum+=nums[i];
            }
        }
        //case 1
        if(singleDigitSum>(total-singleDigitSum)) return true;
        // case 2
        if(doubleDigitSum>(total-doubleDigitSum)) return true;
        // case 3
        return false;
    }
};