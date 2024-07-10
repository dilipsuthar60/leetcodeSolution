class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int i=1;
        int j=n;
        vector<int>result;
        while(i<=j)
        {
            if(k>1){
                if(k&1)result.push_back(i++);
                else result.push_back(j--);
                k--;
            }
            else{
                result.push_back(i++);
            }
        }
        return result;
    }
};