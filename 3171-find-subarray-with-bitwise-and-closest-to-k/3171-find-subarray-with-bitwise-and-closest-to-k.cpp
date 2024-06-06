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
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int result=1e9;
        vector<int>bit(31,0);
        for(int i=0,j=0;i<n;i++){
            update(bit,nums[i],1);
            int andValue=getValue(bit,i-j+1);
            result=min(result,abs(andValue-k));
            while(j<=i&&andValue<k){
                update(bit,nums[j],-1);
                j++;
                andValue=getValue(bit,i-j+1);
                result=min(result,abs(andValue-k));
            }
        }
        return result;
    }
};