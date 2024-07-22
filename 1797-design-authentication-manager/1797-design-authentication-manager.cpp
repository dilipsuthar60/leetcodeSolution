class AuthenticationManager {
public:
    int timeToLive;
    unordered_map<string,int>mp;
    AuthenticationManager(int timeToLive) {
        this->timeToLive=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId]=currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.find(tokenId)!=mp.end()&&currentTime-mp[tokenId]<timeToLive){
            mp[tokenId]=currentTime;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count=0;
        for(auto &it:mp){
            if(currentTime-it.second<timeToLive) count++;
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */