/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int,Employee*>mp;
    int find(int node){
        int sum=mp[node]->importance;
        for(auto it:mp[node]->subordinates){
            sum+=find(it);
        }
        return sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(auto &it:employees){
            mp[it->id]=it;
        }
        return find(id);
    }
};