class Solution {
public:
    double getDiff(double pass,double total){
        return (pass+1)/(total+1)-(pass/total);
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double,double,double>>pq;
        for(auto &classe:classes){
            pq.push({getDiff(classe[0],classe[1]),classe[0],classe[1]});
        }
        while(extraStudents--){
            auto [diff,pass,total]=pq.top();
            pq.pop();
            pq.push({getDiff(pass+1,total+1),pass+1,total+1});
        }
        double totalPassRatio=0.0;
        while(pq.size()){
            auto [_,pass,total]=pq.top();
            pq.pop();
            totalPassRatio+=(pass/total);
        }
        return totalPassRatio/(classes.size());
    }
};