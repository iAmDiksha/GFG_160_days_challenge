#include <bits/stdc++.h>
using namespace std;

//Kadane's Algorithm

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int res = arr[0];
        int curr = arr[0];
        
        for(int i=1; i<arr.size(); i++)
        {
            curr = max(curr+arr[i], arr[i]);
            res = max(curr,res);
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl << "~" << endl;
    }
}
