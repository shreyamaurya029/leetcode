class Solution {
public:
/*

part of memoization code

    int f(int ind, int buy, int cap,vector<int>& prices, int n, vector<vector<vector<int>>> &dp){
        if(cap == 0 || ind == n){
            return 0;
        }
        
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + f(ind+1, 0, cap, prices,n,dp) , 0+f(ind+1,1,cap,prices,n,dp));
        }

        else{
            profit = max(prices[ind] + f(ind+1,1,cap-1, prices,n,dp), 0+f(ind+1,0,cap,prices,n,dp));
        }
    return dp[ind][buy][cap] = profit;

    }

*/

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
//         //there isn't any need for base case coz we have taken 3d array to be array initially.
//         vector<vector<int>>after(2,vector<int>(3,0));
//         vector<vector<int>>cur(2,vector<int>(3,0));


//         for(int ind = n-1; ind>=0; ind--){
//             for(int buy = 0; buy<=1; buy++){
//                 for(int cap =1; cap<=2; cap++){
//                      int profit = 0;
//                     if(buy){
//                         profit = max(-prices[ind] + after[0][cap] , 0+after[1][cap]);
//                     }

//                     else{
//                         profit = max(prices[ind] + after[1][cap-1] , 0+after[0][cap]);
//                     }
                        
//                     cur[buy][cap] = profit;
                   
//                 }
//             }
//             after = cur;
             
//         }
//         return after[1][2];

        //or return cur[1][2];
    // Creating a 3D DP array of size [n+1][2][3] initialized to 0
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // Base case: dp array is already initialized to 0, covering the base case.

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy == 0) { // We can buy the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
                                           -prices[ind] + dp[ind + 1][1][cap]);
                }

                if (buy == 1) { // We can sell the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
                                           prices[ind] + dp[ind + 1][0][cap - 1]);
                }
            }
        }
    }

    // The result is stored in dp[0][0][2] which represents maximum profit after the final transaction.
    return dp[0][0][2];
        
        
    }
};

//for cleare understandincheck the buy and sell stock 2