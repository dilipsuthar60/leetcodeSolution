class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        vector<bool>visited(n,true);
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>>pq;
        for(int i=0;i<n;i++){
            if(s[i]=='*'&&pq.size()){
                auto [ch,index]=pq.top();
                pq.pop();
                visited[-index]=false;
            }
            else{
                pq.push({s[i],-i});
            }
        }
        string result="";
        for(int i=0;i<n;i++)
        {
            if(s[i]!='*'&&visited[i]){
                result+=s[i];
            }
        }
        return result;
    }
};