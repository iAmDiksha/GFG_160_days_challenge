#include <bits/stdc++.h>
using namespace std;

//Stock Buy and Sell – Multiple Transaction Allowed
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        int profit = 0;
        for(int i=0; i<n-1; i++)
        {
            if(prices[i+1] > prices[i])
            {
                profit += prices[i+1]-prices[i];
            }
        }
        return profit;
    }
};


int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;
        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
