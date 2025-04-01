#include <bits/stdc++.h>
using namespace std;
//Stock Buy and Sell – Multiple Transaction Allowed
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        int lmax = prices[0];
        int lmin = lmax;
        int ans = 0;
        for(int i=1; i<n; i++)
        {
            if(prices[i] > lmax)
            {
                lmax = prices[i];
            }
            else{
                ans += (lmax-lmin);
                lmax = lmin = prices[i];
            }
        }
        ans += (lmax-lmin);
        return ans;
    }
};



//{ Driver Code Starts.
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
// } Driver Code Ends