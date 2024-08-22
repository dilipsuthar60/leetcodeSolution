class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int result=0;
        int isActive[2001]={0};
        int n=tasks.size();
        sort(tasks.begin(),tasks.end(),[&](auto &a,auto &b){return a[1]<b[1];});
        for(int i=0;i<n;i++){
            int start=tasks[i][0];
            int end=tasks[i][1];
            int duration=tasks[i][2];
            for(int j=start;j<=end&&duration>0;j++){
                if(isActive[j]) duration--;
            }
            while(duration){
                if(isActive[end]==0){
                    isActive[end]=1;
                    duration--;
                }
                end--;
            }
        }
        for(int i=0;i<2001;i++){
            if(isActive[i]){
                result++;
            }
        }
        return result;
    }
};