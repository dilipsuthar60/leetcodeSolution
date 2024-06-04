class Solution {
public:
    bool possible(vector<int>&nums1,vector<int>&nums2,int k){
        int count=0;
        int i=0,j=0;
        int n=nums1.size();
        int m=nums2.size();
        while(i<n&&j<m){
            if(nums1[i]+k==nums2[j]){
                j++;
            }
            else{
                count++;
            }
            i++;
        }
        if(count>2) return false;
        return true;
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(),nums2.end());
        int result=1e9;
        for(int i=0,n=nums1.size();i<n;i++){
            int value=nums2[0]-nums1[i];
            if(possible(nums1,nums2,value)){
                result=min(result,value);
            }
        }
        return result;
    }
};