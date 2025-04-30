#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        vector<int> res;
        if(mat.empty()) return res;
        int top=0;
        int bt = mat.size()-1;
        int l = 0;
        int r= mat[0].size()-1;
        while(top<=bt && l<=r)
        {
            for(int i=l; i<=r; i++)
            {
                res.push_back(mat[top][i]);
            }
            top++;
            for(int i=top; i<=bt; i++)
            {
                res.push_back(mat[i][r]);
            }
            r--;
            if(top<=bt)
            {
                for(int i=r; i>=l; i--)
                    res.push_back(mat[bt][i]);
                bt--;
            }
            if(l<=r)
            {
                for(int i=bt; i>=top; i--)
                {
                    res.push_back(mat[i][l]);
                }
                l++;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends