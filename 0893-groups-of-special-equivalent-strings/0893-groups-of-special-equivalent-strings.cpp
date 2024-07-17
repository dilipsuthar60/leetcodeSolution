class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        set<string>s;
        for(auto word:words){
            pair<string,string>p;
            for(int i=0;i<word.size();i++){
                if(i&1){
                    p.first+=word[i];
                }
                else{
                    p.second+=word[i];
                }
            }
            sort(p.first.begin(),p.first.end());
            sort(p.second.begin(),p.second.end());
            s.insert(p.first+p.second);
        }
        return s.size();
    }
};