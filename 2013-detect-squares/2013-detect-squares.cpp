class DetectSquares {
public:
    // int dp[1001][1001]={};
    map<pair<int,int>,int>mp;
    DetectSquares() 
    {
        
    }
    void add(vector<int> point) 
    {
        // v.push_back({point[0],point[1]});
        mp[{point[0],point[1]}]++;
    }
    int count(vector<int> point) 
    {
        int count=0;
        int x=point[0];
        int y=point[1];
        for(auto &t:mp)
        {
            pair<int,int>it=t.first;
            if(it.first!=x&&it.second!=y&&(abs(it.first-x)==abs(it.second-y)))
            {
                int f1=mp[{it.first,it.second}];
                int f2=mp[{it.first,y}];
                int f3=mp[{x,it.second}];
                count+=f1*f2*f3;
            }
        }
        return count;
    }
};

/**
 int ans = 0;
        for(auto itr : mp)
        {
            pair<int,int>p = itr.first;
            if(p.first != point[0] and p.second != point[1] and (abs(point[0] - p.first) == abs(point[1] - p.second)))
            {
                int first = mp[{p.first, p.second}];
                int second = mp[{p.first, point[1]}];
                int third = mp[{point[0], p.second}];
                
                int cur = first * second * third;
                ans += cur;
            }
        }
        
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */