class Solution {
public:
    int numberOfChild(int n, int k) {
        int direction =0;
        int index=0;
        while(k--){
            if(direction==0){
                index++;
            }
            else{
                index--;
            }
            if(index==n-1){
                direction = -1;
            }
            if(index==0){
                direction =0;
            }
        }
        return index;
    }
};