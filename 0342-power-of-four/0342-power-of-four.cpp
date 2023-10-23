class Solution {
public:
    bool isPowerOfFour(int N) {
        long long n=N;
        return ((n&(n-1ll))==0)&&((n-1ll)%3==0);
    }
};