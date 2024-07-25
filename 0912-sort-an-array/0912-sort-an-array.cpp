class Solution {
public:
    void mergeList(vector<int>&nums,int l,int mid,int r){
        int size=(r-l+1);
        vector<int>sortedList(size,0);
        int i=l;
        int j=mid+1;
        int k=0;
        while(i<=mid&&j<=r){
            sortedList[k++]=nums[i]<nums[j]?nums[i++]:nums[j++];
        }
        while(i<=mid){
            sortedList[k++]=nums[i++];
        }
        while(j<=r){
            sortedList[k++]=nums[j++];
        }
        for(int k=0;k<size;k++){
            nums[l+k]=sortedList[k];
        }
    }
    void mergeSort(vector<int>&nums,int l,int r){
        if(l>=r) return ;
        int mid=(l+r)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        mergeList(nums,l,mid,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,(int)nums.size()-1);
        return nums;
    }
};