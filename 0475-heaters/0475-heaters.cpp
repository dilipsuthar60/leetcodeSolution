class Solution {
public:
    bool find(vector<int>&houses,vector<int>&heaters,long long r){
        int i=0;
        int j=0;
        while(i<houses.size()&&j<heaters.size()){
            long long left=heaters[j]-r;
            long long right=heaters[j]+r;
            if(left<=houses[i]&&right>=houses[i]){
                i++;
            }
            else{
                j++;
            }
        }
        return i==houses.size();
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        long long l=0;
        long long r=1e18;
        long long ans=0;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        while(l<=r){
            long long mid=(l+r)/2;
            if(find(houses,heaters,mid)){
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
