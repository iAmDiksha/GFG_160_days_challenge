#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    char nonRepeatingChar(string &s) {
        char ch = '$';
        unordered_map<char,int> m; 
        for(int i=0; i<s.size(); i++)
        {
            m[s[i]]++;
        }
        for(int i=0; i<s.size(); i++){
            if(m[s[i]] == 1)
            {
                return s[i];
            }
        }
        return ch;
    }
};



int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

