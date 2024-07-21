class Solution
{
    public:
        vector<int> find(vector<vector < int>> &mat, int k)
        {
            vector<int> ans;
            vector<int> ind(k + 1, 0);
            vector<vector < int>> dp(k + 1);
            for (auto &it: mat)
            {
                dp[it[0]].push_back(it[1]);
                ind[it[1]]++;
            }
            queue<int> q;
            for (int i = 1; i <= k; i++)
            {
                if (ind[i] == 0)
                {
                    q.push(i);
                }
            }
            while (q.size())
            {
                auto temp = q.front();
                q.pop();
                ans.push_back(temp);
                for (auto it: dp[temp])
                {
                    if (--ind[it] == 0)
                    {
                        q.push(it);
                    }
                }
            }
            return ans;
        }
    vector<vector < int>> buildMatrix(int k, vector<vector < int>> &row, vector< vector< int>> &col)
    {
        vector<int> Row = find(row, k);
        vector<int> Col = find(col, k);
        if (Row.size() != k || Col.size() != k)
        {
            return {};
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < k; i++)
        {
            mp[Col[i]] = i;
        }
        vector<vector < int>> ans(k, vector<int> (k, 0));
        for (int i = 0; i < k; i++)
        {
            ans[i][mp[Row[i]]] = Row[i];
        }
        return ans;
    }
};