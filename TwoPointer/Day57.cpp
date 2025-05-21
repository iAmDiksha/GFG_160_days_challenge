#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> countDistinct(vector<int> &arr, int k) {
          int n = arr.size();
          unordered_map<int,int> m;
          vector<int> ans;
          for(int i=0; i<k; i++)
          {
              m[arr[i]]++;
          }
          ans.push_back(m.size());
          int i=0; 
          for(int j=k; j<n; j++)
          {
              m[arr[i]]--;
              if(m[arr[i]]==0)
              {
                  m.erase(arr[i]);
              }
              i++;
              m[arr[j]]++;
             
              ans.push_back(m.size());
          }
          return ans;
      }
  };


int main()
{
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
        vector<int> result = ob.countDistinct(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
    }
    return 0;
}