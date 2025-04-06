#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int total = 0;
        int minSum = arr[0];
        int maxSum = arr[0];
        int currMax = 0;
        int currMin = 0;
        int n = arr.size();
        
        for(int i=0; i<n ; i++)
        {
            currMax = max(currMax+arr[i], arr[i]);
            maxSum = max(maxSum, currMax);
            
            currMin = min(currMin+ arr[i], arr[i]);
            minSum = min(minSum, currMin);
            
            total = total + arr[i];
        }
        if(total == minSum)
        {
            return maxSum;
        }
        return max(total - minSum, maxSum);
        
        // your code here
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends