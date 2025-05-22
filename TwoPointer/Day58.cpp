#include <bits/stdc++.h>
using namespace std;

// Given a string s, find the length of the longest substring without repeating characters.
class Solution {
    public:
      int longestUniqueSubstr(string &s) {
          int n = s.size();
          int left =0, j = 0;
          unordered_map<char,int> m;
          int res =0;
          while(j<n)
          {
              if(m.find(s[j]) != m.end()){
                  int idx = m[s[j]];
                  if(left <= idx)
                  left = idx+1;
              }
               m[s[j]] = j;
               res = max(res,j-left+1);
               j++;
          }
          return res;
      }
  };

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        int result = ob.longestUniqueSubstr(s);
        cout << result << endl;
    }
    return 0;
}
  