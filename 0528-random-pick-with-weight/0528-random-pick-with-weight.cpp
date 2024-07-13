class Solution {
public:
    vector<int>prefix;
    Solution(vector<int>& w) {
        for(int i=0,n=w.size();i<n;i++){
            prefix.push_back(prefix.empty()?w[i]:w[i]+prefix.back());
        }
        // for(int i=0;i<w.size();i++){
        //     for(int j=0;j<w[i];j++){
        //         prefix.push_back(i);
        //     }
        // }
    }
    
    int pickIndex() {
        int totalSum=prefix.back();
        int index=rand()%totalSum;
        int ans=upper_bound(prefix.begin(),prefix.end(),index)-prefix.begin();
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */