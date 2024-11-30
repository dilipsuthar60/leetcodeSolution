class FrequencyTracker {
public:
    unordered_map<int,int>mp;
    multiset<int>freq;
    FrequencyTracker() {
        freq.clear();
        mp.clear();
    }
    
    void add(int number) {
        if(mp.find(number)!=mp.end()){
            int previousFreq=mp[number];
            freq.erase(freq.find(previousFreq));
        }
        mp[number]++;
        freq.insert(mp[number]);
    }
    
    void deleteOne(int number) {
        if(mp.find(number)!=mp.end()){
            int previousFreq=mp[number];
            freq.erase(freq.find(previousFreq));
            if(--mp[number]==0){
                mp.erase(number);
            }
            else{
                freq.insert(mp[number]);
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return freq.find(frequency)!=freq.end();
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */