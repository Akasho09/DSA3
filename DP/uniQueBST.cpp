// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

class Solution {
public: 
    int solve(int n , vector<int>&dp){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        int t = 0;
        for(int i=1;i<=n;i++){
            int l = solve(i-1 , dp);
            int r = solve(n-i , dp);
            t+=l*r;
        }
        return dp[n]=t;
    }
    int numTrees(int n){
        vector<int>dp(n+1, -1);
        return solve(n , dp);
    }
};