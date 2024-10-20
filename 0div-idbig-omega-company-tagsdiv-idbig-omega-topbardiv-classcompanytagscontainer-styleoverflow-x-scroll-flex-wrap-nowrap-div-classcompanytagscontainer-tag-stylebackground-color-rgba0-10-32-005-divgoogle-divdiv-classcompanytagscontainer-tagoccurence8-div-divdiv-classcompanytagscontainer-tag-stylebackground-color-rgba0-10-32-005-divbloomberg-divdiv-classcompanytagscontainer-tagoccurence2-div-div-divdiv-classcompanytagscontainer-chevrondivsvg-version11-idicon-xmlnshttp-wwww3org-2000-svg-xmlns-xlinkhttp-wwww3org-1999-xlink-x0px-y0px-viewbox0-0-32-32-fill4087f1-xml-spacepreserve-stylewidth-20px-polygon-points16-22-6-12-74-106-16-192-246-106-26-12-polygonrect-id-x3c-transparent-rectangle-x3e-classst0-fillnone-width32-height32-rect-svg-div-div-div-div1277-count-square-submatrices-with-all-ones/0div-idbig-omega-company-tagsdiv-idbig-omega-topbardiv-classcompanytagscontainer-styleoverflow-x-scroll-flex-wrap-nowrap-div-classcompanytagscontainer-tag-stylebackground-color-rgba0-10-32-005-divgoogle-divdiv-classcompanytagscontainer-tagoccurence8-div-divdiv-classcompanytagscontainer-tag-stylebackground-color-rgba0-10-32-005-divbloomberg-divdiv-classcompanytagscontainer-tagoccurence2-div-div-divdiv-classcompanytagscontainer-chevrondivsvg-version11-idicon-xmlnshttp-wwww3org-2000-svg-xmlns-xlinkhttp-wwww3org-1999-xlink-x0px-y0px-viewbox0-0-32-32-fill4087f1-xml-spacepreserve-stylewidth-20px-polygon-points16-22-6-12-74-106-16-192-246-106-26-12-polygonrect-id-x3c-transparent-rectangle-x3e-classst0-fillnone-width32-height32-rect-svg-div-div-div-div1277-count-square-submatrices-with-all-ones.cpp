class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

      //look for square right bottom
        // 0 1 1 1 
        // 1 1 1 1
        // 0 1 1 1
            
      //forming the dp[i][j] table
    /*
    for first 0 we'll form 
    */
        int n = matrix.size();
        int m= matrix[0].size();

        vector<vector<int>>dp(n, vector<int>(m,0));

        for(int j=0; j<m; j++) dp[0][j] = matrix[0][j]; // for first row
        for(int i=0; i<n; i++) dp[i][0] = matrix[i][0]; //for first column

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){

                if(matrix[i][j] == 0) dp[i][j] = 0;

                else{

                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) ;
                }
            }
        }

        int sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                sum+=dp[i][j];
            }
        }

        return sum;

    }
};