class Solution {
public:
    int lcs(string &word1,string &word2,int i,int j,vector<vector<int>> &dp){
        if(i==word1.length() || j==word2.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int output;
        if(word1[i]==word2[j]){
            output = lcs(word1,word2,i+1,j+1,dp) + 1;
            dp[i][j] = output;
            return output;
        }
        int a = lcs(word1,word2,i+1,j,dp);
        int b = lcs(word1,word2,i,j+1,dp);
        output = max(a,b);
        dp[i][j] = output;
        return output;
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        int l = lcs(word1,word2,0,0,dp);
        return n+m - 2*l;
    }
};