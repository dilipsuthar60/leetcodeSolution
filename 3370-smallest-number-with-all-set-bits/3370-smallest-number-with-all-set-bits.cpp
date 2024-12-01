class Solution {
public:
    int smallestNumber(int n) {
        int bitCount=log2(n)+1;
        return (1<<bitCount)-1;
    }
};