class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
       int n=s.size();  
        int space=0;
        int dis=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L')
            {
                dis--;
            }
            else if(s[i]=='R')
            {
                dis++;
            }
            else
            {
                space++;
            }
        }
        return space+abs(dis);
    }
};