class Solution {
public:
    int minimumOneBitOperations(int n) 
    {
        int mask=n;
        while(mask)
        {
            mask=mask>>1;
            n=n^mask;
        }
        return n;
    }
};