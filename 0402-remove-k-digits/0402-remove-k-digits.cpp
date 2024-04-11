class Solution {
public:
    string removeKdigits(string num, int k)
    {
        string s="";
        for(auto&ch:num)
        {
            while(s.size()&&s.back()>ch&&k>0)
            {
                k--;
                s.pop_back();
            }
            if(s.size()||ch!='0')
            {
                s.push_back(ch);
            }
        }
        while(s.size()>0&&k>0)
        {
            k--;
            s.pop_back();
        }
        return s.size()==0?"0":s;
    }
};