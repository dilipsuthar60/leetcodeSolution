class Solution {
public:
    int counter(int n,long curr,long next){
        int count=0;
        while(curr<=n){
            count+=next-curr;
            curr*=10;
            next*=10;
            next=min(next,n+1l);
        }
        return count;
    }
    int findKthNumber(int n, int k) {
        int curr=1;
        k--;
        while(k>0){
            int count=counter(n,curr,curr+1);
            if(count<=k){
                k-=count;
                curr++;
            }
            else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};