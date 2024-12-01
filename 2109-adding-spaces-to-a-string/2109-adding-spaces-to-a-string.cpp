class Solution {
public:
    string addSpaces(string s, vector<int>& nums) {
        string result="";
        for(int i=0,j=0;i<s.size();i++){
            if(j<nums.size()&&i==nums[j]){
                result+=" ";
                j++;
            }
            result+=s[i];
        }
        return result;
    }
};