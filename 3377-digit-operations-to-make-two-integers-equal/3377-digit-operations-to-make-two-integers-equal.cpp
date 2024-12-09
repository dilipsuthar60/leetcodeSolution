class Solution {
public:
    vector<int>isPrime;
    void seive(){
        isPrime=vector<int>(1e5,1);
        isPrime[0]=isPrime[1]=0;
        for(int i=2;i<1e5;i++){
            if(isPrime[i]){
                for(int j=2*i;j<1e5;j+=i){
                    isPrime[j]=0;
                }
            }
        }
    }
    int minOperations(int n, int m) {
        seive();
        if(isPrime[n]||isPrime[m]){
            return -1;
        }
        unordered_set<int>visited;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({n,n});
        while(!pq.empty()){
            auto [cost,num]=pq.top();
            pq.pop();
            if(num==m){
                return cost;
            }
            if(visited.find(num)!=visited.end()){
                continue;
            }
            visited.insert(num);
            string current=to_string(num);
            for(int i=0;i<current.size();i++){
                char original=current[i];
                if(current[i]!='9'){
                    current[i]++;
                    int number=stoi(current);
                    if(!isPrime[number]){
                        pq.push({number+cost,number});
                    }
                    current[i]--;
                }
                if(current[i]!='0'){
                    current[i]--;
                    int number=stoi(current);
                    if(!isPrime[number]){
                        pq.push({number+cost,number});
                    }
                    current[i]++;
                }
            }
        }
        return -1;
    }
};