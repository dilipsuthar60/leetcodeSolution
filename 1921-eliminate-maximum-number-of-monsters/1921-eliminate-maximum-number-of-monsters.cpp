class Solution {
public:
    int eliminateMaximum(vector<int>& d, vector<int>& s) 
    {
        int n=d.size();
        vector<double>v;
        for(int i=0;i<n;i++)
        {
            v.push_back((double)((1.0)*d[i]/s[i]));
        }
        sort(v.begin(),v.end());
       for(int i=0;i<n;i++)
       {
           if(i>=v[i])
           {
               return i;
           }
       }
        return n;
    }
};