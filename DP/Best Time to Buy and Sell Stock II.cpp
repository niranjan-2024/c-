//Recursive Solution
class Solution {
public:
    
    int solve(vector<int> &prices,int buy,int index,int n){
        if(index==n){
            return 0;
        }
            int profit = 0;
            
            if(buy==0){
                profit = max(0+solve(prices,0,index+1,n),-prices[index]+solve(prices,1,index+1,n));
            }
            if(buy==1){
                profit = max(0+solve(prices,1,index+1,n),prices[index]+solve(prices,0,index+1,n));
            }
            
            return profit;
            
        }
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(prices, 0 , 0, n);
    }
};




//Recursive+Memoization
class Solution {
public:
    
    int solve(vector<int> &prices,int buy,int index,int n,vector<vector<int>> &dp){
        if(index==n){
            return 0;
        }
        
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        
        int profit = 0;
            
        if(buy==0){
            profit = max(0+solve(prices,0,index+1,n,dp),-prices[index]+solve(prices,1,index+1,n,dp));
        }
        if(buy==1){
             profit = max(0+solve(prices,1,index+1,n,dp),prices[index]+solve(prices,0,index+1,n,dp));
        }
            
        dp[index][buy] = profit;
        return dp[index][buy];
            
        }
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices, 0 , 0, n,dp);
    }
};





//Tabulation
class Solution {
public:
    
    int solve(vector<int> &prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        
        dp[n][0] = 0;
        dp[n][1] = 0;
        
        int profit = 0;
        for(int index = n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                     profit = max(0+dp[index+1][0],-prices[index]+dp[index+1][1]);
                   }
                if(buy==1){
                     profit = max(0+dp[index+1][1],prices[index]+dp[index+1][0]);
                   }
                dp[index][buy] = profit;
            }
        }
        
            
        
        return dp[0][0];
            
        }
    
    
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};




//Space optimization
class Solution {
public:
    
    int solve(vector<int> &prices){
        int n = prices.size();
        vector<int> next(2,0);
        vector<int> curr(2,0);
        
        next[0] = 0;
        next[1] = 0;
        
        int profit = 0;
        for(int index = n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                     profit = max(0+next[0],-prices[index]+next[1]);
                   }
                if(buy==1){
                     profit = max(0+next[1],prices[index]+next[0]);
                   }
                curr[buy] = profit;
            }
            next = curr;
        }
        
                  
        return curr[0];
            
        }
    
    
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};



//Improved Space Optimization
class Solution {
public:
    
    int solve(vector<int> &prices){
        int n = prices.size();
        vector<int> next(2,0);
        
        next[0] = 0;
        next[1] = 0;
        
        int profit = 0;
        for(int index = n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                     profit = max(0+next[0],-prices[index]+next[1]);
                   }
                if(buy==1){
                     profit = max(0+next[1],prices[index]+next[0]);
                   }
                next[buy] = profit;
            }
        }
        
                  
        return next[0];
            
        }
    
    
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};
