#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        int i = 0;
        int cnt =0;
        int j = arr.size()-1;
        while(i<j)
        {
            int sum = arr[i]+arr[j];
            if(sum < target)  {
                cnt += j-i;
                i++;
            }
            else{
                j--;
            }
        }
        return cnt;
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends