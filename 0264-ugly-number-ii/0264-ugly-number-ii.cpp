class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        vector<int>nums(n,0);
        nums[0]=1;
        int p2,p3,p5;
        p2=p3=p5=0;
        for(int i=1;i<n;i++){
            int currentValue=min({nums[p2]*2,nums[p3]*3,nums[p5]*5});
            if(currentValue==nums[p2]*2){
                p2++;
            }
            if(currentValue==nums[p3]*3){
                p3++;
            }
            if(currentValue==nums[p5]*5){
                p5++;
            }
            nums[i]=currentValue;
        }
        return nums.back();
    }
};