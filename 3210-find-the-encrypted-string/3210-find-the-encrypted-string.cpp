class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n=s.size();
        string temp=s;
        for(int i=0;i<n;i++)
        {
            s[i]=temp[(i+k)%n];
        }
        return s;
    }
};