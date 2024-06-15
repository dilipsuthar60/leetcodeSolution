class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& item, int k) {
        long long ans=0;
        int size=item.size();
        sort(item.begin(),item.end(),[&](auto &a,auto &b){return a[0]>b[0];});
        unordered_set<int>seen;
        vector<int>duplicateProfit;
        long long profit=0;
        int index=0;
        for(auto &it:item)
        {
            int currentProfit=it[0];
            int currentCategory=it[1];
            if(index++<k){
                if(seen.find(currentCategory)!=seen.end()){
                    duplicateProfit.push_back(currentProfit);
                }
                profit+=currentProfit;
            }
            else if (seen.find(currentCategory)==seen.end()){
                if(duplicateProfit.size()==0) return ans;
                profit+=currentProfit-duplicateProfit.back();
                duplicateProfit.pop_back();
            }
            seen.insert(currentCategory);
            long long distint=seen.size()*seen.size();
            ans=max(ans,profit+distint);
        }
        return ans;
    }
};