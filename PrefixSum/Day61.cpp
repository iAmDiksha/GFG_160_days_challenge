#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // Function to find equilibrium point in the array.
      int findEquilibrium(vector<int> &arr) {
          int lsum =0;
          int sum =0;
          for(int i=0; i<arr.size(); i++)
          {
              sum += arr[i];
          }
          int rsum = sum;
          for(int i=0; i<arr.size(); i++)
          {
              rsum = rsum - arr[i];
              if(lsum == rsum)
              {
                  return i;
              }
              lsum += arr[i];
          }
          return -1;
      }
  };

int main() {
    Solution ob;
    vector<int> arr = {1, 3, 5, 2, 2};
    int result = ob.findEquilibrium(arr);
    cout << result << endl; // Output: 2
    return 0;
}