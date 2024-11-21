class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>s(banned.begin(),banned.end());
        int number=0;
        int currentRunningSum=0;
        for(int i=1;i<=n;i++){
            if(s.find(i)==s.end()&&currentRunningSum+i<=maxSum){
                number++;
                currentRunningSum+=i;
            }
        }
        return number;
    }
};