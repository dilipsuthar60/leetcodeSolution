class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        vector<int>digit(10,-1);
        for(int i=0;i<s.size();i++){
            digit[s[i]-'0']=i;
        }
        for(int i=0;i<s.size();i++){
            for(int k=9;k>s[i]-'0';k--){
                if(digit[k]>i){
                    swap(s[i],s[digit[k]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};