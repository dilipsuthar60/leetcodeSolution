class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int n=words.size();
        vector<int>sizes;
        vector<int>freq(26,0);
        for(int i=0;i<n;i++)
        {
            sizes.push_back(words[i].size());
            for(auto &ch:words[i])
            {
                freq[ch-'a']++;
            }
        }
        sort(sizes.begin(),sizes.end());
        int even=0;
        int odd=0;
        for(int i=0;i<26;i++)
        {
            if(freq[i])
            {
                even+=freq[i]/2;
                odd+=freq[i]%2;
            }
        }
        int totalPalindrome=0;
        for(auto size:sizes)
        {
            int needEven=size/2;
            int needOdd=size%2;
            if(needEven>even) break;
            if(needOdd>odd)
            {
                even--;
                odd+=2;
            }
            even-=needEven;
            odd-=needOdd;
            totalPalindrome++;
        }
        return totalPalindrome;
    }
};