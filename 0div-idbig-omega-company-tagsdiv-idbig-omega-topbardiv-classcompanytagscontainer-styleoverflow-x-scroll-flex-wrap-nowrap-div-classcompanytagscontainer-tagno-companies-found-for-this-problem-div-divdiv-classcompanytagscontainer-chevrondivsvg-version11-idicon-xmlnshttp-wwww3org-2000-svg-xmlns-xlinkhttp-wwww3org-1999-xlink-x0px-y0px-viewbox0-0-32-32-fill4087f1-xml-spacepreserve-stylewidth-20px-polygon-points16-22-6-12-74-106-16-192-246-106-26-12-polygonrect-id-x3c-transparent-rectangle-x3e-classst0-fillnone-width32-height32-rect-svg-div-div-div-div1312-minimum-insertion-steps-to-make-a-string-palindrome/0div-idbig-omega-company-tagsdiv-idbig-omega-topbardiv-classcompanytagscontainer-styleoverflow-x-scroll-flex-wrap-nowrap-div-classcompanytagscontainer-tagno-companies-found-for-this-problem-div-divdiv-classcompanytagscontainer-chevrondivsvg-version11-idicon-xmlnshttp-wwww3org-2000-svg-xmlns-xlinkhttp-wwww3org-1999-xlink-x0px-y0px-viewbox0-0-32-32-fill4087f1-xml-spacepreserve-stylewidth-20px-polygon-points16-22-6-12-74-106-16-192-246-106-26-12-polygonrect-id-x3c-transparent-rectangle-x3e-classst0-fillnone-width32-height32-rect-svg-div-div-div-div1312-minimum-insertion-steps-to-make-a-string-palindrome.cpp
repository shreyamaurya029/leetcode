class Solution {
public:
int lcs(string s, string t) {
        
       int n = s.size();
       int m = t.size();
//        vector<int> prev(m+1,0), cur(m+1,0);
//        //for(int i=0; i<n; i++) dp[i][0] = 0;
//        for(int j=0; j<m; j++) prev[j] = 0;

//        for(int i=1; i<=n; i++){
//            for(int j=1; j<=m; j++){
//                if(s[i-1] == t[j-1]) cur[j] = 1+prev[j-1];

//                else cur[j] = max(prev[j], cur[j-1]);
//            }
//         prev = cur;
//        }
//       return prev[m];  
    
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(s[i]==t[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
     return dp[0][0];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
}
    int minInsertions(string s) {
       return s.size() - longestPalindromeSubseq(s);
    }
};

/*
    insertions one has to do = n(len of string) - largest palindromic subsequence

*/