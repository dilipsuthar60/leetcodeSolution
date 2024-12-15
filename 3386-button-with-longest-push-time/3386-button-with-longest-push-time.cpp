class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int ans=events[0][0];
        int overAllMaxTime=events[0][1];
        for(int i=1;i<events.size();i++){
            int currentPressTime=(events[i][1]-events[i-1][1]);
            if(currentPressTime>=overAllMaxTime){
                if(currentPressTime==overAllMaxTime){
                    ans=min(ans,events[i][0]);
                }
                else{
                    ans=events[i][0];
                }
                overAllMaxTime=currentPressTime;
            }
        }
        return ans;
    }
};