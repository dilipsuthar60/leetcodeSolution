class Solution {
public:
    int row,col;
    set<pair<int,int>>s;
    Solution(int m, int n) {
        this->row=m;
        this->col=n;
    }
    
    vector<int> flip() {
        int x=rand()%row;
        int y=rand()%col;
        if(s.find({x,y})==s.end()) {
            s.insert({x,y});
            return {x,y};
        }
        return flip();
    }
    
    void reset() {
        s.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */