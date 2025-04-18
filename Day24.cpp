#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        int res = 0;
        sort(arr.begin(), arr.end());
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i][0] <= arr[res][1])
            {
                arr[res][1] = max(arr[res][1],arr[i][1]);
            }
            else{
                res++;
                arr[res] = arr[i];
            }
        }
        vector<vector<int>> ans;
        
        for(int i=0; i<=res; i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends