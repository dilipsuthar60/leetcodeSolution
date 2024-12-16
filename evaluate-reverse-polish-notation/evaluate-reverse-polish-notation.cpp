class Solution {
public:
    int evalRPN(vector<string>& t) 
    {
        stack<int>s;
        for(auto it:t)
        {
            if(it.size()>1||isdigit(it[0]))
            {
                s.push(stoi(it));
            }
            else if(it[0]=='+')
            {
                int va1=s.top();
                s.pop();
                int val2=s.top();
                s.pop();
                s.push(va1+val2);
            }
            else if(it[0]=='-')
            {
                int va1=s.top();
                s.pop();
                int val2=s.top();
                s.pop();
                s.push(-va1+val2);
            }
            else if(it[0]=='*')
            {
                int va1=s.top();
                s.pop();
                int val2=s.top();
                s.pop();
                s.push(1ll*val2*va1);
            }
            else if(it[0]=='/')
            {
                int va1=s.top();
                s.pop();
                int val2=s.top();
                s.pop();
                s.push(val2/va1);
            }
        }
        return s.top();
    }
};