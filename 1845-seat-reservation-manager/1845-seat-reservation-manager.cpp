class SeatManager {
public:
    map<int,int>mp;
    SeatManager(int n) 
    {
        for(int i=0;i<n;i++)
        {
            mp[i]=i+1;
        }
    }
    
    int reserve() 
    {
       int val=mp.begin()->second;
        mp.erase(mp.begin());
        return val;
    }
    
    void unreserve(int s) 
    {
        mp[s-1]=s;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */