#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
      void solve(string s, unordered_set<string> &st, int idx)
      {
          if(idx == s.size()){
              st.insert(s);
              return;
          }
          
          for(int j=idx; j<s.size(); j++)
          {
              swap(s[idx],s[j]);
              solve(s,st,idx+1);
              //backtrack
              swap(s[idx],s[j]);
          }
      }
      
      vector<string> findPermutation(string &s) {
         vector<string> ans;
         unordered_set<string> st;
         int idx = 0;
         solve(s,st,idx);
         for(string val: st)
         {
             ans.push_back(val);
         }
         return ans;
      }
  };

  int main()
  {
        string s;
        cin >> s;
        Solution ob;
        vector<string> ans = ob.findPermutation(s);
        sort(ans.begin(), ans.end());
        for(string val: ans)
        {
            cout << val << " ";
        }
        cout << endl;
        return 0;
  }