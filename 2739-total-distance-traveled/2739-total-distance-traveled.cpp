class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int travel=0;
        for(int i=1;i<=mainTank;i++)
        {
            if(additionalTank!=0&&i%5==0)
            {
                travel+=10;
                additionalTank--;
                mainTank++;
            }
            else
            {
                travel+=10;
            }
        }
         return travel;
    }
};