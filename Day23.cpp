#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int count(vector<int> &arr, int l, int m, int r)
  {
      int n1 = m-l+1, n2 = r-m;
      vector<int> left(n1), right(n2);
      for(int i=0; i<n1; i++)
      {
          left[i] = arr[i+l];
      }
      for(int j = 0;j<n2; j++)
      {
          right[j] = arr[m+1+j];
      }
      int res =0;
      int i=0, j = 0, k=l;
      while(i<n1 && j <n2)
      {
          if(left[i] <=right[j])
          {
              arr[k++] = left[i++];
          }
          else{
              arr[k++] = right[j++];
              res += (n1-i);
          }
      }
      while(i<n1)
      arr[k++] = left[i++];
      while(j<n2) arr[k++] = right[j++];
      return res;
  }
    // Function to count inversions in the array.
    int countI(vector<int> &arr, int l, int r)
    {
        int res =0;
        if(l<r) {
            int m = (r+l)/2;
            res += countI(arr,l,m);
            res += countI(arr,m+1,r);
            
            res += count(arr,l,m,r);
        }
        return res;
    }
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return countI(arr,0,n-1);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends