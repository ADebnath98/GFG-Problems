//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        int n=A.length();
       vector<vector<int>>dp(n, vector<int>(n,0));
       for(int i=0; i<n; i++)
       dp[i][i]=1;
       for(int i=1; i<n; i++){
           for(int j=0; j<n-i; j++){
               int len=j+i;
               if(A[j]==A[len] && i==1)
               dp[j][len]=2;
               else if(A[j]==A[len])
               dp[j][len]=dp[j+1][len-1]+2;
               else
               dp[j][len]=max(dp[j][len-1], dp[j+1][len]);
           }
       }
       return dp[0][n-1];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends