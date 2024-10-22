class Solution {
public:
//     int f(int ind, int buy, vector<int>& prices, int n, vector<vector<int>> &dp){
       

//         if(ind == n) return 0;
//         if(dp[ind][buy] != -1) return dp[ind][buy];
//         int profit = 0;

//         if(buy){    //buying and then one cannot buy any further  didn't buy and can buy f urther
//             profit = max(-prices[ind] +f(ind+1, 0,prices,n,dp), 0 + f(ind+1, 1,prices,n,dp));
//         }

//         else{      //sell and then buy stock.               don't sell u cannot buy
//             profit = max(prices[ind] + f(ind+1,1,prices,n,dp),0+f(ind+1,0,prices,n,dp));
//         }

//         return dp[ind][buy] = profit;


//     }


    int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        long profit = 0;
        for(int ind=n-1; ind>=0; ind--){
            for(int buy = 1; buy>=0; buy--){
                if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -prices[ind] + dp[ind + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], prices[ind] + dp[ind + 1][0]);
            }

            dp[ind][buy] = profit;
            }
        }
        return dp[0][0];


//         //vector<vector<int>> dp(n+1, vector<int>(2,0));
//         vector<long> ahead(2,0), cur(2,0);

//         ahead[0] = cur[1] = 0;

//         for(int ind=n-1; ind>=0;ind--){
//             for(int buy=0; buy<=1;buy++){
//                 int profit = 0;

//         if(buy){    //buying and then one cannot buy any further  didn't buy and can buy further
//             profit = max(-prices[ind]+ahead[0],0+ahead[1]);
//         }

//         else{      //sell and then buy stock.               don't sell u cannot buy
//             profit = max(prices[ind]+ahead[1],0+ahead[0]);
//         }

//         cur[buy] = profit;
//             }
//             ahead = cur;
//         }


//         return ahead[1];        
    }
};