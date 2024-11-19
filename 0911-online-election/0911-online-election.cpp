class TopVotedCandidate {
public:
    map<int,int>mp;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int,int>count;
        int n=persons.size();
        int lead=-1;
        int maxCount=-1;
        for(int i=0;i<n;i++){
            if(++count[persons[i]]>=maxCount){
                maxCount=count[persons[i]];
                lead=persons[i];
            }
            mp[times[i]]=lead;
        }
    }
    
    int q(int t) {
        auto it=mp.upper_bound(t);
        return prev(it)->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */