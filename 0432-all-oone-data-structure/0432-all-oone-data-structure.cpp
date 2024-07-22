class AllOne {
public:
    unordered_map<string,int>mp;
    set<pair<int,string>>s;
    AllOne() {
        
    }
    
    void inc(string key) 
    {
        if(mp.find(key)==mp.end()){
            mp[key]++;
            s.insert({mp[key],key});
        }
        else{
            s.erase(s.find({mp[key],key}));
            mp[key]++;
            s.insert({mp[key],key});
        }
    }
    
    void dec(string key) {
        if(mp.find(key)!=mp.end()){
            if(mp[key]==1){
                s.erase(s.find({mp[key],key}));
                mp.erase(key);
            }
            else{
                s.erase(s.find({mp[key],key}));
                mp[key]--;
                s.insert({mp[key],key});
            }
        }
    }
    
    string getMaxKey() {
        if(s.size()){
            auto it=*s.rbegin();
            return it.second;
        }
        return "";
    }
    
    string getMinKey() {
        if(s.size()){
            auto it=*s.begin();
            return it.second;
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */