class Solution {
public:
    void update(vector<int>&bit,int num,int value){
        for(int i=0;i<31;i++)
        {
            if(num&(1<<i)){
                bit[i]+=value;
            }
        }
    }
    int getValue(vector<int>&bit,int count){
        int result=0;
        for(int i=0;i<31;i++)
        {
            if(bit[i]==count) result+=(1<<i);
        }
        return result;
    }
    long long find(vector<int>&nums,int k){
        long long count=0;
        int n=nums.size();
        vector<int>bit(32,0);
        for(int i=0,j=0;i<n;i++){
            update(bit,nums[i],1);
            while((i-j+1)>0&&getValue(bit,i-j+1)<k){
                update(bit,nums[j],-1);
                j++;
            }
            count+=(i-j+1);
        }
        return count;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        return find(nums,k)-find(nums,k+1);
    }
};