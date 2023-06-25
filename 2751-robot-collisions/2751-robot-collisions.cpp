class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>&p, vector<int>& h, string d) 
    {
        int n=p.size();
        vector<pair<int,int>>nums;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            nums.push_back({p[i],i});
        }
        sort(nums.begin(),nums.end());
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            int position=nums[i].first;
            int index=nums[i].second;
            if(s.size()==0&&d[index]=='L')
            {
                continue;
            }
            if(d[index]=='R')
            {
                s.push(index);
            }
            else
            {
                while(s.size())
                {
                    auto temp=s.top();
                    s.pop();
                    if(h[temp]==h[index])
                    {
                        h[temp]=0;
                        h[index]=0;
                        break;
                    }
                    else if(h[temp]<h[index])
                    {
                        h[temp]=0;
                        h[index]--;
                    }
                    else
                    {
                        h[temp]--;
                        h[index]=0;
                        s.push(temp);
                        break;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(h[i])
            {
                ans.push_back(h[i]);
            }
        }
        return ans;
    }
};