class Solution {
public:
    int countSeniors(vector<string>& s) {
        int count=0;
        for(auto it:s){
            count+=stoi(it.substr(11,2))>60;
        }
        return count;
    }
};