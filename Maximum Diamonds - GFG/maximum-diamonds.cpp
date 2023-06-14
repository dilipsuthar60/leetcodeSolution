//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
        // code here
        priority_queue<int>pq;
        for(int i=0;i<N;i++)
        {
            pq.push(A[i]);
        }
        long long cost=0;
        while(pq.size()&&K--)
        {
            int val=pq.top();
            pq.pop();
            cost+=val;
            pq.push(val/2);
        }
        return cost;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends