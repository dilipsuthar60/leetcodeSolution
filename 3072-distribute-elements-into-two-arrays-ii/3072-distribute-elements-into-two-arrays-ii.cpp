class Solution {
public:
    int N;
    void update(int i,int val,vector<int>&bit)
    {
        while(i<N)
        {
            bit[i]+=val;
            i+=(i&-i);
        }
    }
    int find(int i,vector<int>&bit)
    {
        int sum=0;
        while(i>0)
        {
            sum+=bit[i];
            i-=(i&-i);
        }
        return sum;
    }
    vector<int> resultArray(vector<int>& nums) 
    {
        N=nums.size()+5;
        vector<int>bit1(N,0),bit2(N,0);
        vector<int>arr1,arr2;
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        map<int,int>mp;
        for(int i=0;i<temp.size();i++)
        {
            mp[temp[i]]=i+1;
        }
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        update(mp[nums[0]],1,bit1);
        update(mp[nums[1]],1,bit2);
        for(int i=2;i<nums.size();i++)
        {
            int greaterCount1=arr1.size()-find(mp[nums[i]],bit1);
            int greaterCount2=arr2.size()-find(mp[nums[i]],bit2);
            if(greaterCount1>greaterCount2)
            {
                arr1.push_back(nums[i]);
                update(mp[nums[i]],1,bit1);
            }
            else if(greaterCount1<greaterCount2)
            {
                arr2.push_back(nums[i]);
                update(mp[nums[i]],1,bit2);
            }
            else
            {
                if(arr1.size()<arr2.size())
                {
                    arr1.push_back(nums[i]);
                    update(mp[nums[i]],1,bit1);
                }
                else if(arr1.size()>arr2.size())
                {
                    arr2.push_back(nums[i]);
                    update(mp[nums[i]],1,bit2);
                }
                else{
                    arr1.push_back(nums[i]);
                    update(mp[nums[i]],1,bit1);
                }
            }
        }
        for(auto &it:arr2) arr1.push_back(it);
        return arr1;
    }
};