class Solution {
public:
    int find(vector<vector<int>>&mat,int mid){
        int count=0;
        for(auto vec:mat){
            count += upper_bound(vec.begin(),vec.end(),mid)-vec.begin();
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int l=mat[0][0];
        int r=mat[n-1][n-1];
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(find(mat,mid)>=k){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
