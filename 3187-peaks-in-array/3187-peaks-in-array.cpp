class Solution {
public:
    vector<int>bit;
    bool isPeak(int index,vector<int>&nums)
    {
        return index>0&&index+1<nums.size()&&nums[index-1]<nums[index]&&nums[index]>nums[index+1];
    }
    void update(int i,int value){
        i++;
        while(i<bit.size()){
            bit[i]+=value;
            i+=(i&-i);
        }
    }
    int find(int i){
        i++;
        int sum=0;
        while(i>0){
            sum+=bit[i];
            i-=(i&-i);
        }
        return sum;
    }
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        bit.resize(n+1);
        for(int i=0;i<n;i++){
            if(isPeak(i,nums)){
                update(i,1);
            }
        }
        vector<int>result;
        for(auto query:queries){
            int type=query[0];
            if(type==1){
                int l=query[1];
                int r=query[2];
                result.push_back(max(0,find(r-1)-find(l)));
            }else{
                int index=query[1];
                int value=query[2];
                for(int i=index-1;i<=index+1;i++)
                {
                    if(isPeak(i,nums)){
                       update(i,-1);   
                    }
                }
                nums[index]=value;
                for(int i=index-1;i<=index+1;i++)
                {
                    if(isPeak(i,nums)){
                        update(i,1);   
                    }
                }
            }
        }
        return result;
    }
};