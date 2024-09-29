class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long ans=0;
        int l=0;
        int r=skill.size()-1;
        int total=skill.front()+skill.back();
        while(l<r){
            if(total!=skill[l]+skill[r]) return -1;
            ans+=skill[l++]*skill[r--];
        }
        return ans;
    }
};