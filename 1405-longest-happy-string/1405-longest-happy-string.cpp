class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        string result="";
        while(pq.size()){
            auto [currentFreq,currentChar]=pq.top();
            pq.pop();
            int sizeOfResult=result.size();
            if(sizeOfResult>=2&&result[sizeOfResult-1]==currentChar&&result[sizeOfResult-2]==currentChar){
                if(pq.empty()) return result;
                auto [nextFreq,nextChar]=pq.top();
                pq.pop();
                result.push_back(nextChar);
                nextFreq--;
                if(nextFreq) pq.push({nextFreq,nextChar});
                pq.push({currentFreq,currentChar});
            }
            else{
                result.push_back(currentChar);
                currentFreq--;
                if(currentFreq) pq.push({currentFreq,currentChar});
            }
        }
        return result;
    }
};