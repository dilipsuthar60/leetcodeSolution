class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bit=__builtin_popcount(num2);
        int x=0;
        for(int i=31;i>=0&&bit;i--){
            if((num1&(1<<i))>0){
                x|=(1<<i);
                bit--;
            }
        }
        if(bit>0){
            for(int i=0;i<32&&bit;i++){
                if((num1&(1<<i))==0){
                    x|=(1<<i);
                    bit--;
                }
            }
        }
        return x;
    }
};