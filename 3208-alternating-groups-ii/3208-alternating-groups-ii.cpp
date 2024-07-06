class Solution {
public:
    vector<int>kmp(string s,string p){
        s=p+"###"+s;
        int n=s.size();
        vector<int>result(n,0);
        int i=1;
        int len=0;
        while(i<n){
            if(s[i]==s[len]){
                result[i]=++len;
                i++;
            }
            else{
                if(len){
                    len=result[len-1];
                }
                else{
                    i++;
                }
            }
        }
        return result;
    }
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        for(int i=0;i<k-1;i++){
            nums.push_back(nums[i]);
        }
        string s="";
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) s.push_back('0');
            if(nums[i]==1) s.push_back('1');
        }
        string p1="";
        string p2="";
        for(int i=0;i<k;i++){
            if(i%2==0){
                p1.push_back('0');
                p2.push_back('1');
            }
            else{
                p1.push_back('1');
                p2.push_back('0');
            }
        }
        int count=0;
        vector<int>result1=kmp(s,p1);
        vector<int>result2=kmp(s,p2);
        
        for(int i=0;i<result2.size();i++){
            if(result1[i]==k||result2[i]==k){
                count++;
            }
        }
        return count;
    }
};