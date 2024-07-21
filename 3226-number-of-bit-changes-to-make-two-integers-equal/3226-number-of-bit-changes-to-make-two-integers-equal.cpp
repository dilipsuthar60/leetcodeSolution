class Solution {
public:
    int minChanges(int n, int k) {
        int change=0;
        for(int i=0;i<31;i++){
            int currentBitn=(n&(1<<i))>0;
            int currentBitk=(k&(1<<i))>0;
            if(currentBitn==currentBitk) continue;
            if(currentBitn==0&&currentBitk==1) return -1;
            change++;
        }
        return change;
    }
};