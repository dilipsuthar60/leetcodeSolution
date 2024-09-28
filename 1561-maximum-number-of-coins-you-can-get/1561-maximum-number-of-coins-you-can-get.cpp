class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        deque<int>dq;
        for(auto &pile:piles) dq.push_back(pile);
        int result=0;
        while(dq.size()){
            dq.pop_back();
            result+=dq.back();
            dq.pop_back();
            dq.pop_front();
        }
        return result;
    }
};