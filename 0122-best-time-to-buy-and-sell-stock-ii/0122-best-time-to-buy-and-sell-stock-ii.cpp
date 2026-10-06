class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(); 
        int i=0;
        int j=1;
        int buy=0;
        int profit=0;

        while(j<n){
            if (prices[j]>prices[i]){
                i++;
                j++;
            }
            else{
                profit += prices[i]-prices[buy];
                buy=j;
                i=j;
                j++;
            }
        }
        profit += prices[i]-prices[buy];
        return profit;
    }
};