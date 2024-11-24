class Solution {
public:
    long long getCost(vector<int>&cost,string &s,int start,int end,int direction=1){
        long long currentCost=0;
        while(start!=end){
            currentCost+=cost[start];
            start=(start+direction)%26;
        }
        return currentCost;
    }
    long long shiftDistance(string s, string t, vector<int>& next, vector<int>& prev) {
        long long cost=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                int indexS=(s[i]-'a');
                int indexT=(t[i]-'a');
                long long forwordCost=getCost(next,s,indexS,indexT);
                long long backwordCost=getCost(prev,s,indexS,indexT,25);
                cost+=min(forwordCost,backwordCost);
            }
        }
        return cost;
    }
};