#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  //Stock Buy and Sell – Max one Transaction Allowed
    int maximumProfit(vector<int> &prices) {
        int mn = prices[0];
        int profit = 0;
        for(int i=1; i<prices.size(); i++)
        {
            mn = min(prices[i], mn);
            profit = max(profit,prices[i]-mn);
        }
        return profit;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}
