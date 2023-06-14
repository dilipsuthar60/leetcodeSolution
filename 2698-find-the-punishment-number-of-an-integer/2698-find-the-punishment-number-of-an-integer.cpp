class Solution {
public:
    int  find(string &s,int index,int target)
    {
        if(index>=s.size()||target<0)
        {
            return target==0;
        }
        for(int i=index;i<s.size();i++)
        {
            int value=stoi(s.substr(index,i-index+1));
            if(find(s,i+1,target-value))
            {
                return 1;
            }
        }
        return 0;
    }
    int punishmentNumber(int n) {
        int cost=0;
        for(int i=1;i<=n;i++)
        {
            string s=to_string(i*i);
            if(find(s,0,i))
            {
                cost+=i*i;
            }
        }
        return cost;
    }
};