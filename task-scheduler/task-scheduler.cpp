class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>mp;
        for(auto&task:tasks){
            mp[task]++;
        }
        priority_queue<int>pq;
        for(auto &[key,value]:mp)
        {
            pq.push(value);
        }
        int time=0;
        while(pq.size())
        {
            queue<int>remainTask;
            int run = n+1; 
            while(pq.size()&&run)
            {
                auto freq = pq.top();
                pq.pop();
                if(--freq)
                {
                    remainTask.push(freq);
                }
                time++;
                run--;
            }
            while(remainTask.size())
            {
                pq.push(remainTask.front());
                remainTask.pop();
            }
            if(pq.size()==0) break;
            time += run;
        }
        return time;
    }
};