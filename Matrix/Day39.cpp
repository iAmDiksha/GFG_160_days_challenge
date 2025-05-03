#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool search(vector<int> &arr, int x)
    {
        int lo = 0, hi = arr.size();
        while(lo <= hi)
        {
            int mid = (lo+hi)/2;
            if(x == arr[mid])
            {
                return true;
            }
            if(x<arr[mid])
            {
                hi=mid-1;
            }
            else{
                lo = mid+1;   
            }
        }
        return false;
    }
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size(), m = mat[0].size();
        for(int i=0; i<n; i++)
        {
            if(search(mat[i],x)) return true;
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends