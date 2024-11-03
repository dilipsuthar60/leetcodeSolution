class Solution {
public:
    bool rotateString(string A, string B) 
    {
        if(A.size()!=B.size())
        {
            return false;
        }
        A=A+A;
        if(A.find(B)!=string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};