#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // transpose the matrix
        int n = mat.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n ; j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }
        // i->column (reverse the colum wise matrix)
        for(int i=0; i<n ;i++)
        {
            int top =0, bottom = n-1;
            while(top<bottom)
            {
                swap(mat[top][i],mat[bottom][i]);
                top++;
                bottom--;
            }
        }
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends