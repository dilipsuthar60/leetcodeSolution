class Solution {
public:
    bool check(vector<int>&block,int size,int k){
        int count=0;
        for(int i=0;i<block.size();i++){
            count+=(block[i]/(size+1));
        }
        return count<=k;
    }
    int minLength(string s, int numOps) {
        vector<int>block;
        char prev=s[0];
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(prev==s[i]){
                count++;
            }
            else{
                block.push_back(count);
                count=1;
                prev=s[i];
            }
        }
        block.push_back(count);
        for(int i=1;i<=n;i++){
            if(i==1){
                int count=0;
                for(int j=0;j<n;j++){
                    if((s[j]-'0')!=j%2){
                        count++;
                    }
                }
                int o=min(count,n-count);
                if(o<=numOps){
                    return 1;
                }
            }
            else{
                    if(check(block,i,numOps)){
                        return i;
                    }
            }
        }
        return *max_element(block.begin(),block.end());
    }
};