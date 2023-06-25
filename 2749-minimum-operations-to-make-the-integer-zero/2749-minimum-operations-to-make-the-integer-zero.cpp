class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) 
    {
       if(num2>num1)
       {
           return -1;
       }
        for(int i=0;i<=100;i++)
        {
            long long value=num1-1ll*num2*i;
            int bit=__builtin_popcountll(value);
            if(bit<=i&&i<=value)
            {
                return i;
            }
        }
        return -1;
    }
};