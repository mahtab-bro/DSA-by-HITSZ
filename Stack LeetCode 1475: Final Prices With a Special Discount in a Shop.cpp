Full Question
You are given an integer array prices where prices[i] is the price of the ith item in a shop.

There is a special discount: if you buy the ith item, you receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you receive no discount.

Return an array answer where answer[i] is the final price you pay for the ith item.

---------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> answer = prices;  // Start with original prices
        stack<int> st;  // Stack stores INDICES waiting for discount
        
        for (int i = 0; i < n; i++) {
            // While top of stack has price >= current price
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                // Current price is the discount for the item at st.top()
                int idx = st.top();
                answer[idx] = prices[idx] - prices[i];  // Apply discount
                st.pop();  // This item's discount is found, remove it
            }
            st.push(i);  // Current item waiting for its discount
        }
        
        return answer;  // Items still in stack have no discount (unchanged)
    }
};
