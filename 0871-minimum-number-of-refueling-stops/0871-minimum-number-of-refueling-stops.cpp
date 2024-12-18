class Solution {
public:
    int minRefuelStops(int target, int start, vector<vector<int>>&nums) 
    {
        int i=0;
        int res=0;
        // multiset<int,greater<int>>m;
        //insert and delete item O(log(n)) // red black tree<->AVL tree
        priority_queue<int >pq;
        int count=0;
        while(start<target)
        {
            count++;
            while(i<nums.size()&&nums[i][0]<=start)
            {
                pq.push(nums[i++][1]);
            }
            if(pq.size()==0)
            {
                return -1;
            }
            start+=pq.top();
            pq.pop();
        }
        return count;
    }
};