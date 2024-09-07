class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int>result;
        int heightOfTree=log2(label)+1;
        result.push_back(label);
        while(label>0){
            int leftNode=(1<<(heightOfTree-1));
            int rightNode=(1<<heightOfTree)-1;
            label=(leftNode+rightNode-label)/2;
            result.push_back(label);
            heightOfTree--;
        }
        result.pop_back();
        reverse(result.begin(),result.end());
        return result;
    }
};