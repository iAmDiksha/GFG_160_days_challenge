#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
      double power(double b, int e) {
          // code here
          return pow(b,e);
      }
  };

int main() {
    double b;
    int e;
    cin >> b >> e;
    Solution ob;
    cout << fixed << setprecision(6) << ob.power(b, e) << endl;
    return 0;
}