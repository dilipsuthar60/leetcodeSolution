class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<=k){
            string temp=s;
            for(int i=0;i<temp.size();i++){
                int index=temp[i]-'a';
                index=(index+1)%26;
                temp[i]=char('a'+index);
            }
            s+=temp;
        }
        return s[k-1];
    }
};