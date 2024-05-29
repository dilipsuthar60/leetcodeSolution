class Solution {
public:
    string getSmallestString(string s, int k) {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int distance=min(abs('a'-s[i]),abs('z'-s[i])+1);
            if(distance<=k)
            {
                s[i]='a';
                k-=distance;
            }
            else{
                s[i]=s[i]-k;
                return s;
            }
        }
        return s;
    }
};