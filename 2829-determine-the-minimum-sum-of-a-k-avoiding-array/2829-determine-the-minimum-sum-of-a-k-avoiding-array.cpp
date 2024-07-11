class Solution {
public:
    int minimumSum(int n, int k) {
        int ans=0;
        unordered_set<int>s;
        for(int i=1;i<=n;i++){
            if(s.find(k-i)==s.end()){
                ans+=i;
                s.insert(i);
            }
            else{
                n++;
            }
        }
        return ans;
    }
};