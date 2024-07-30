class Solution {
public:
    int minimumDeletions(string s)
    {
        int count=0;
        stack<char>st;
        int n=s.size();
        int deleted=0;
        for(int i=0;i<n;i++){
            if(st.size()&&st.top()=='b'&&s[i]=='a'){
                st.pop();
                deleted++;
            }
            else{
                st.push(s[i]);
            }
        }
        return deleted;
    }
};