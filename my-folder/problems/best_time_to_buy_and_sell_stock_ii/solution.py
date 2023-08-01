class Solution:
    """
   
     
    
    
    
    """
    
    
    
    def maxProfit(self, prices: List[int]) -> int:
        l = 0
        n = len(prices)
        sum=0
        for i in range(1, n):
            if (prices[i] > prices[i-1]) :
                sum += prices[i] - prices[i-1]
                
        return sum
                
    
        
        