class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) 
    {
        sort(coins.begin(),coins.end());
        long long covered=0;
        int ans=0;
        for(auto &it:coins)
        {
            while(it>covered+1)
            {
                ans++;
                covered+=covered+1;
            }
            covered+=it;
        }
           while(covered<target)
            {
                ans++;
                covered+=covered+1;
            }
        return ans;
    }
};
 // sort(coins.begin(), coins.end());
 //        int minimum = 0;
 //        long long covered = 0;
 //        for (int i : coins) {
 //            while (i > covered + 1) {
 //                covered += (covered + 1);
 //                ++minimum;
 //            }
 //            covered += i;
 //        }
 //        while (covered < target) {
 //            covered += (covered + 1);
 //            ++minimum;
 //        }
 //        return minimum;