class Solution {
public:
    int countStudents(vector<int>& nums, vector<int>& sand) 
    {
        int n=nums.size();
        queue<int>q;
        for(int i=0;i<nums.size();i++) q.push(nums[i]);
        
        int index=0;
        int rotation=0;
        while(q.size()&&rotation<q.size())
        {
            if(q.front()==sand[index])
            {
                q.pop();
                index++;
                rotation=0;
            }
            else
            {
                int item=q.front();
                q.pop();
                q.push(item);
                rotation++;
            }
        }
        return q.size();
    }
};