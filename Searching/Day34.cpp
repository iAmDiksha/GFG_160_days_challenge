#include <bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
class Solution {
  public:
  
  bool isPossible( vector<int> &arr, int k, int mid)
  {
      int students = 1;
      int currSum = 0;
      for(int i =0; i<arr.size(); i++)
      {
          if(arr[i]> mid)
          {
              return false;
          }
          if(currSum + arr[i]> mid)
          {
              students++;
              currSum = arr[i];
              if(students > k)
              {
                  return false;
                  
              }
          }
          else{
              currSum += arr[i];
          }
          
      }
      return true;
  }
    int findPages(vector<int> &arr, int k) {
       if(arr.size()<k)
       {
           return -1;
       }
       int l = *max_element(arr.begin(),arr.end());
       int r = accumulate(arr.begin(),arr.end(),0);
       int res = INT_MAX;
       while(l<=r)
       {
           int mid = l+(r-l)/2;
           if(isPossible(arr,k,mid))
           {
               res = min(res, mid);
               r = mid-1;
           }
           else{
               l = mid+1;
           }
       }
       return res;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends