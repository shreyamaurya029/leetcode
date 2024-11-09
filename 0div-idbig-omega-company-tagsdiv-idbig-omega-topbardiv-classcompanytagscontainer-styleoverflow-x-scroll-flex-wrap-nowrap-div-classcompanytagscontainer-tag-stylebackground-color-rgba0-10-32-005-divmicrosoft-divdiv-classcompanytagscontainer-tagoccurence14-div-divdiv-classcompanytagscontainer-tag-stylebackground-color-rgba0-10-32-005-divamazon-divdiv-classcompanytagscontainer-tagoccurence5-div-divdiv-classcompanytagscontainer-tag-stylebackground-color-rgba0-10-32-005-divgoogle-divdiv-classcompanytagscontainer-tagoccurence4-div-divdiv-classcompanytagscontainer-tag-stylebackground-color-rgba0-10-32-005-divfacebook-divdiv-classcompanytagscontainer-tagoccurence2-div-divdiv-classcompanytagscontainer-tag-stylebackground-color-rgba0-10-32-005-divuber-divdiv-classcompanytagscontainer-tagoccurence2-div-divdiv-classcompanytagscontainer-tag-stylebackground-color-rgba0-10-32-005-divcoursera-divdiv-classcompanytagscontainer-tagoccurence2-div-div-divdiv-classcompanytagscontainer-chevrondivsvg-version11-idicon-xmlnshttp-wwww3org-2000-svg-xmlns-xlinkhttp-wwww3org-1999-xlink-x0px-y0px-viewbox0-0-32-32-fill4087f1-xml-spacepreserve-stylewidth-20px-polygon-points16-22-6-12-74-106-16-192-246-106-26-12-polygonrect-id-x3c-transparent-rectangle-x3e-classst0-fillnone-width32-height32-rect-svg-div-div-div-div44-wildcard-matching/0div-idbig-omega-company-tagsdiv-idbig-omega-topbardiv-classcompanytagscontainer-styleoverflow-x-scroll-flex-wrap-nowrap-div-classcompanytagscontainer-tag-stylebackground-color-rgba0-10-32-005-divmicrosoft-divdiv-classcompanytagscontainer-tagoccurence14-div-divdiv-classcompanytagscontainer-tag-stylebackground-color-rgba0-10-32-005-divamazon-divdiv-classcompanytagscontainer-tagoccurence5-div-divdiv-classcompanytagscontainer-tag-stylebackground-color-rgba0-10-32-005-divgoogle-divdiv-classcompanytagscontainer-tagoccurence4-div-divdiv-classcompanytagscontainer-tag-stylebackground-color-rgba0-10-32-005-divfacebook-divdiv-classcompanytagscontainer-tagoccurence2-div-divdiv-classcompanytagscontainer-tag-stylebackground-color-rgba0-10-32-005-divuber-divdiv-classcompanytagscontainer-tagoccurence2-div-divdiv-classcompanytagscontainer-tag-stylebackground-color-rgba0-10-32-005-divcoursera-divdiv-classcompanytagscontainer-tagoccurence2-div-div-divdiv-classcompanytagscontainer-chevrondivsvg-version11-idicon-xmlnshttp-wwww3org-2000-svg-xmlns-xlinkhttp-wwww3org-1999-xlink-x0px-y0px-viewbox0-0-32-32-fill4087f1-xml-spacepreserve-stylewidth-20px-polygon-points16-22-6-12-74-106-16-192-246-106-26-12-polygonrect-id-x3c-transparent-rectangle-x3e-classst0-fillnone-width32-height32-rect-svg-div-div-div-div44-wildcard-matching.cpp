class Solution {
public:
    bool isMatch(string S1, string S2) {
        
        int n = S1.size();
        int m = S2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
         dp[n][m] = 1;

        for (int i = n; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i < n && (S1[i] == S2[j] || S2[j] == '?')) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else if (S2[j] == '*') {
                    if(i<n){
                        dp[i][j] = dp[i+1][j] || dp[i][j+1];
                    }
                    else{
                         dp[i][j] = dp[i][j+1];
                    }
                    
                }
            }
        }

        return dp[0][0];
    }
};