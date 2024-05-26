class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int n=word.size();
        char ch=word[0];
        int currentCount=0;
        for(int i=0;i<n;i++)
        {
            if(ch==word[i])
            {
                currentCount++;
                if(currentCount==9)
                {
                    ans+=to_string(currentCount)+string(1,ch);
                    currentCount=0;
                }
            }
            else
            {
                if(currentCount)
                ans+=to_string(currentCount)+string(1,ch);
                currentCount=1;
                ch=word[i];
            }
        }
        if(currentCount)
        {
            ans+=to_string(currentCount)+string(1,ch);
        }
        return ans;
    }
};