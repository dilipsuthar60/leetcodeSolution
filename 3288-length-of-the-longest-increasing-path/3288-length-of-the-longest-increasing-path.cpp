class Solution {
public:
    int findLis(vector<vector<int>>&nums){
        sort(nums.begin(),nums.end(),[&](auto &a,auto &b){
            return (a[0]==b[0])?a[1]>b[1]:a[0]<b[0];
        });
        
        set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            auto it=s.lower_bound(nums[i][1]);
            if(it!=s.end()){
                s.erase(it);
            }
            s.insert(nums[i][1]);
        }
        cout<<s.size()<<endl;
        return s.size();
    }
    int maxPathLength(vector<vector<int>>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>a,b;
        for(int i=0;i<nums.size();i++){
            if(nums[i][0]<nums[k][0]&&nums[i][1]<nums[k][1]){
                a.push_back(nums[i]);
            }
            if(nums[i][0]>nums[k][0]&&nums[i][1]>nums[k][1]){
                b.push_back(nums[i]);
            }
        }
        return findLis(a)+findLis(b)+1;
    }
};