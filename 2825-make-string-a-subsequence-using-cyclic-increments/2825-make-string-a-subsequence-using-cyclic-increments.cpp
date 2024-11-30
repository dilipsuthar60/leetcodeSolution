class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int i=0,j=0;
        while(i<n&&j<m){
            if(str1[i]==str2[j]){
                j++;
            }
            else{
                int index1=(str1[i]-'a');
                int index2=(str2[j]-'a');
                cout<<(index1+1)%26<<endl;
                cout<<(index1+25)%26<<endl;
                if(((index1+1)==index2)){
                    j++;
                }
                if(index1==25&&(index2==0)){
                    j++;
                }
            }
            i++;
        }
        return j==str2.size();
    }
};