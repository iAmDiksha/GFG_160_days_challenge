#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
       int n = arr.size();
       
       int i = 0;
       int j = 0;
       int sum =0;
       vector<int> v;
       while(j<n)
       {
           sum = sum + arr[j];
           while(sum > target && i<=j)
           {
               sum = sum - arr[i];
               i++;
           }
           if(sum == target)
           {
               v = {i+1,j+1};
               return v;
           }
           else{
               j++;
           }
       }
       return {-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends