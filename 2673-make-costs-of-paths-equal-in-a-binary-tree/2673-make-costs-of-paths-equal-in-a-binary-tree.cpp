class Solution {
public:
    int result;
    vector<int>nums;
    int find(int node)
    {
        if(node>=nums.size())
        {
            return 0;
        }
        int left=find(2*node+1);
        int right=find(2*node+2);
        result+=abs(left-right);
        return nums[node]+max(left,right);
        
    }
    int minIncrements(int n, vector<int>& cost) 
    {
        this->result=0;
        this->nums=cost;
        find(0);
        return result;
    }
};